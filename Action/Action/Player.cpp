#include "Player.h"
#include <math.h>
#include <typeinfo.h>
#include <cstdlib>
#include "DxLib.h"
#include "Keyboard.h"
#include "Terrain.h"
#include "Item.h"

//課題点：Itemを持っている状態でジャンプし、天井にぶつかると、Itemを持っていない場合と比較して滞空時間が長くなる
//			(Itemの位置更新がPlayerの移動及びCarryonの接触判定より遅れているため)
//対応法その1：Checkの引数numにgravityの値を加算して判定を行う、問題点：二つの関数に同じ値の定数を使用することになる。
//		その2：CarryonのCheckを行う前にCarryonのUpdateを行う、問題点：Playerの上にピッタリと乗るようになり、更新のずれによる"持っている感"が無くなる恐れあり。
//		その3：Item側で判定を行わず、Player側でCarryonのheightとwidthを元に当たり判定の計算を行う、問題点：widthとheightをprivateにすることが不可能になる。
//課題点:Itemの横幅がPlayerよりも大きい状態で、持ってるItemに引っかかっているときの挙動が変

Player::Player(float x, float y, float height, float width, int object_number) : Object(x, y, height, width, object_number) {
	switch (this->object_number_) {
	case 0:
		graph_handle_ = LoadGraph("Image/Player_2.png");
		break;
	default:
		break;
	}
	quality_ = true;
	vector_ = 1;
	angle_ = 0;
	dance_timer_ = 0;
	dance_num_ = 0;
	is_carrier_ = false;
	player_state_ = Player_Air;
}
//プレイヤーのボタン入力を管理
void Player::Action() {
	const float kSpeed = 5.0f;
	if (Keyboard::getInstance()->CheckKey(KEY_INPUT_RIGHT) != 0) { //右キーが押されていたら
		vector_ = 1;
		//Move(&x_, kSpeed);//右に移動する
		MoveX(kSpeed);//右に移動する
	}
	if (Keyboard::getInstance()->CheckKey(KEY_INPUT_LEFT) != 0) { //左キーが押されていたら
		vector_ = -1;
		//Move(&x_, -kSpeed);//左に移動する
		MoveX(-kSpeed);//左に移動する
	}
	//上キーを入力されたとき
	if ((Keyboard::getInstance()->CheckKey(KEY_INPUT_UP) == 1 && player_state_ == Player_Land) ||//プレイヤーが地上にいるときか
		(Keyboard::getInstance()->CheckKey(KEY_INPUT_UP) > 1 && angle_ != 0)) {//上キーを入力し続けているとき
		Jump();
	}
	else if (angle_ != 0) {//上キーの入力をしていないとき、またはジャンプ中に入力をやめたとき
		angle_ = 0;//angleを0に設定する
	}
	//Spaceキーを入力したとき
	if (Keyboard::getInstance()->CheckKey(KEY_INPUT_SPACE) == 1) { 
		//何かものを持っているなら
		if (is_carrier_) Throw();//Throw動作を行う
			else Pick(); //Pick動作を行う
	}
	//下キーを入力したとき、何か持っていたなら
	if (Keyboard::getInstance()->CheckKey(KEY_INPUT_DOWN) == 1 && is_carrier_)
		Put();//Put動作を行う

	if (Keyboard::getInstance()->CheckKey(KEY_INPUT_LCONTROL) == 1 || Keyboard::getInstance()->CheckKey(KEY_INPUT_RCONTROL) == 1)
		vector_ *= -1;

}
void Player::Push(float num, Object *object) {
	if (object->CanMoveX(num / 4)) {
		object->MoveX(num / 4);
		MoveX(num / 4);
		if (is_carrier_)carryon_->MoveX(num / 4);
	}
}
//プレイヤーがItemを拾う動作
void Player::Pick() {
	Object *goods = nullptr;
	for (auto i : *stage_) {//ステージ上のオブジェクトから検索
		if (Check(i) &&//
			(goods == nullptr ||
				abs(this->x_ - i->x_) < abs(this->x_ - goods->x_) ||
				(abs(this->x_ - i->x_) == abs(this->x_ - goods->x_) &&
				( i->Base() < goods->Base())))) {
			goods = i;//持ち上げる対象を設定する
		}
	}
	if (goods != nullptr && goods->CanPicked(this)) {
		goods->Picked(this);
		is_carrier_ = true;
		carryon_ = goods;
	}
}
void Player::Put() {
	if (carryon_->CanPutted()) {
		carryon_->Putted();
		is_carrier_ = false;
	}
}
void Player::Throw() {
	if (carryon_->CanThrew()) {
		carryon_->Threw();
		is_carrier_ = false;
	}
}
//プレイヤーがPick動作を行う際、objectが一定の範囲内にあるかCheckする関数
//引数:
//		object:確認するObject
bool Player::Check(Object *object) {
	bool check = false;
	if (object->quality_ &&object !=this && Base() > object->Top() && Top() < object->Base()) {
		if (vector_ == 1 &&//Playerが右を向いているとき
			Right() <= object->Left() && Right() + width_ >= object->Left()) {
			check = true;
		}
		else if(vector_ == -1 &&//Playerが左を向いているとき
			Left() >= object->Right() && Left() - width_ <= object->Right()){
			check = true;
		}
	}
	return check;
}
//----------
//PlayerがObjectに当たった際の位置の調整とPlayerの状態を変更する
//引数：
//		check:int Check(float *point, float num,const Object *object)の返り値から、オブジェクトのどこに当たったかを求める
//		object:当ったオブジェクト
void Player::Hit(int check, Object * object) {
	if (typeid(*object) == typeid(Terrain) || typeid(*object) == typeid(Item)) {
		switch (check) {
		case 1:
			x_ = object->Left() - width_ ;
			break;
		case 2:
			x_ = object->Right();
			break;
		case 3:
			y_ = object->Top() - height_;
			player_state_ = Player_Land;
			break;
		case 4:
			angle_ = 45;
			y_ = object->Base();
		default:
			break;
		}
	}
}
//----------
//Carryon(Playerが持っているItem)がObjectに当たった際の位置の調整とPlayerの状態を変更する
//引数：
//		check:int Check(float *point, float num,const Object *object)の返り値から、オブジェクトのどこに当たったかを求める
//		object:当ったオブジェクト
void Player::HitCarryon(int check,Object *object) {
	if (typeid(*object) == typeid(Terrain) || typeid(*object) == typeid(Item)) {
		switch (check) {
		case 1:
			carryon_->x_ = object->Left() - carryon_->width_;
			x_ = (carryon_->Left() + carryon_->Right() - this->width_) / 2;
			break;
		case 2:
			carryon_->x_ = object->Right();
			x_ = (carryon_->Left() + carryon_->Right() - this->width_) / 2;
			break;
		case 3:
			carryon_->y_ = object->Top() - carryon_->height_;
			y_ = carryon_->Base();
			player_state_ = Player_Land;
			break;
		case 4:
			carryon_->y_ = object->Base();
			y_ = carryon_->Base();
		default:
			break;
		}
	}
}
//Playerのジャンプ動作
void Player::Jump() {
	if (angle_ > 90) angle_ = 90;//上キーを入力し続けてもcos(angle_ * 3.141592f * 1 / 120)が0になるようにする
	const float kJumpPower = 8;
	MoveY(-kJumpPower * (float)cos(angle_ * 3.141592f * 1 / 120));
	angle_++;//angleを増加し続ける
}
int Player::MapCheck(float num) {
	int check = 0;
	if (Right() + num > map_right_->Right()) check = 1;
	else if (Left() + num < map_left_->Left()) check = 2;
	return check;
}
void Player::MapHit(int mapcheck) {
	switch (mapcheck) {
	case 1:
		x_ = map_right_->Right() - width_;
		break;
	case 2:
		x_ = map_left_->Left();
		break;
	default:
		break;
	}
}
//穴に落ちたかの確認
void Player::RetryCheck() {
	if(y_ > 480.0f) player_state_ = Player_Retry;//画面下に落ちた場合、プレイヤーをリトライ状態にする
}
//クリア時に踊るダンスを管理する
void Player::Dance() {
	switch (dance_num_) {
	//case 0:
	//	vector_ = -1;
	//	x_ += 2;
	//	dance_timer_++;
	//	if (dance_timer_ > 60) {//60/60fps = 1秒移動したとき
	//		dance_num_++;//次の移動に移行する
	//		dance_timer_ = 0;//タイマーをリセットする
	//	}
	//	break;
	//case 1:
	//	vector_ = 1;
	//	x_ -= 2;
	//	dance_timer_++;
	//	if (dance_timer_ > 90) {
	//		dance_num_++;
	//		dance_timer_ = 0;
	//	}
	//	break;
	//case 2:
	//	vector_ = -1;
	//	x_ += 2;
	//	dance_timer_++;
	//	if (dance_timer_ > 30) {
	//		dance_num_++;
	//		dance_timer_ = 0;
	//	}
	//	break;
	//case 3:
	//	vector_ = -1;
	//	y_ -= 2;
	//	dance_timer_++;
	//	if (dance_timer_ > 15) {
	//		dance_num_++;
	//		dance_timer_ = 0;
	//	}
	//	break;
	//case 4:
	//	vector_ = -1;
	//	y_ += 2;
	//	dance_timer_++;
	//	if (dance_timer_ > 15) {
	//		dance_num_++;
	//		dance_timer_ = 0;
	//	}
	//	break;
	//case 5:
	//	vector_ = 1;
	//	y_ -= 2;
	//	dance_timer_++;
	//	if (dance_timer_ > 45) {
	//		dance_num_++;
	//		dance_timer_ = 0;
	//	}
	//	break;


	//case 0:
	//	vector_ = -1;
	//	y_ -= 2;
	//	dance_timer_++;
	//	if (dance_timer_ > 15) {
	//		dance_num_++;
	//		dance_timer_ = 0;
	//	}
	//	break;
	//case 1:
	//	vector_ = -1;
	//	y_ += 2;
	//	dance_timer_++;
	//	if (dance_timer_ > 15) {
	//		dance_num_++;
	//		dance_timer_ = 0;
	//	}
	//	break;
	//case 2:
	//	vector_ = -1;
	//	y_ += 2;
	//	dance_timer_++;
	//	if (dance_timer_ > 15) {
	//		dance_num_++;
	//		dance_timer_ = 0;
	//	}
	//	break;
	//case 3:
	//	vector_ = 1;
	//	y_ -= 2;
	//	dance_timer_++;
	//	if (dance_timer_ > 45) {
	//		dance_num_++;
	//		dance_timer_ = 0;
	//	}
	//	break;
	default:
		state_changer_->ChangeState(Game_Clear);
		break;
	}
}
void Player::Initialize(IStateChanger *stateChanger,std::vector<Object*>& stage){
	Object::Initialize(stateChanger, stage);
	map_left_, map_right_ = nullptr;
	for (auto i : *stage_) {
		if (typeid(*i) == typeid(Terrain)) {
			if (map_left_ == nullptr) map_left_ = i;
			else if (map_left_->Left() > i->Left()) map_left_ = i;
			if (map_right_ == nullptr) map_right_ = i;
			else if (map_right_->Right() < i->Right()) map_right_ = i;
		}
	}
}
void Player::Update() {
	switch (player_state_) {
	case Player_Clear:
		Dance();
		break;
	case Player_Retry:
			state_changer_->ChangeState(Game_Retry);
			break;
	default:
		const float kGravity = 4.0f;
		MoveY(kGravity);
		Action();	
		RetryCheck();
		break;
	}
}
void Player::Draw() {
	if(vector_ ==1) DrawModiGraphF(x_, y_, x_ + width_, y_, x_ + width_, y_ + height_, x_, y_ + height_, graph_handle_, TRUE);
	else DrawModiGraphF(x_ + width_, y_, x_, y_, x_, y_ + height_, x_ + width_, y_ + height_, graph_handle_, TRUE);
}
//Playerが移動する軸にnumを追加した結果、objectに接触するか、した場合にはどの部分に接触したかを返す
//返り値:
//		0:接触なし
//		1:objectの左側に接触
//		2:objectの右側に接触
//		3:objectの上側に接触
//		4:objectの下側に接触
//引数:
//		point:移動する軸、&xか&yを入力する
//		num:移動する軸に加算する数字(移動する距離)
//		object:接触するか判定を行うObject
int Player::CheckX(float num, const Object *object) {
	int check = 0;
	if (object->quality_ &&
		((!is_carrier_ && object != this) ||//物を持っていない時、本人を除く
		(is_carrier_ && object != carryon_ && object != this))) {//物を持っているとき、持っているものがPlayerに対する接触判定をなくす
		if (Object::Check(x_ + num,y_, object)) {
			if (num > 0) check = 1;//地形の上側から衝突した時
			else check = 2;//地形の下から衝突した時
		}
	}
	return check;
}
int Player::CheckY(float num, const Object *object) {
	int check = 0;
	if (object->quality_ &&
		((!is_carrier_ && object != this) ||//物を持っていない時、本人を除く
		(is_carrier_ && object != carryon_ && object != this))) {//物を持っているとき、持っているものがPlayerに対する接触判定をなくす
		if (Object::Check(x_,y_ + num, object)) {
			if (num > 0) check = 3;//地形の上側から衝突した時
			else check = 4;//地形の下から衝突した時
		}
	}
	return check;
}
//Playerが他のObjectによって移動される場合、動かすことができるかを返す
bool Player::CanMoveX(float num) {
	bool can_move = true;
	for (int i = 0; i != (*stage_).size();i++) {
		if (CheckX(num, (*stage_)[i]) != 0 && (*stage_)[i]->CanMoveX(num/4)) {
			can_move = false;
			break;
		}
	}
	return can_move;
}
//Playerが他のObjectによって移動される場合、動かすことができるかを返す
bool Player::CanMoveY(float num) {
	bool can_move = true;
	for (int i = 0; i != (*stage_).size();i++) {
		if (CheckY(num, (*stage_)[i]) != 0 && (*stage_)[i]->CanMoveY(num/4)) {
			can_move = false;
			break;
		}
	}
	return can_move;
}
//プレイヤーの移動を行う
void Player::MoveX(float num) {
	bool hit = false;
	if (is_carrier_) {//何か背負っているとき
		for (auto i : (*stage_)) {
				//背負っている物の当たり判定をチェックする
			if (carryon_->CheckX(num, i) != 0) {
				//オブジェクトに接触している時
				//if (player_state_ == Player_Land) {
				//	//横軸に移動しようとしているとき尚且つプレイヤーが地面にいるとき
				//	Push(num, i);//オブジェクトを押す
				//}
				HitCarryon(carryon_->CheckX(num, i), i);//Hitした時のプレイヤーの位置を調整する
				hit = true;
				break;
			}
		}
	}
	if (!hit) {//何も背負ってないとき、または背負っているものは何も当たらない場合
		for (auto i : (*stage_)) {
			if (CheckX(num, i) != 0) {
				if (player_state_ == Player_Land) {
					//横軸に移動しようとしているとき尚且つプレイヤーが地面にいるとき
					Push(num, i);//オブジェクトを押す
				}
				Hit(CheckX(num, i), i);//Hitした時のプレイヤーの位置を調整する
				hit = true;
				break;
			}
		}
	}
	//マップ外に移動してしまうか確認する処理
	if (MapCheck(num) != 0) {
		hit = true;
		MapHit(MapCheck(num));
	}
	if (!hit) {//移動先に何もオブジェクトがなく、マップ外に移動しない場合
		x_ += num;
	}
}
//プレイヤーの移動を行う
void Player::MoveY(float num) {
	bool hit = false;
	if (is_carrier_) {//何か背負っているとき
		for (auto i : (*stage_)) {
				//背負っている物の当たり判定をチェックする
			if (carryon_->CheckY(num, i) != 0) {
				HitCarryon(carryon_->CheckY(num, i), i);//Hitした時のプレイヤーの位置を調整する
				hit = true;
				break;
			}
		}
	}
	if (!hit) {//何も背負ってないとき、または背負っているものは何も当たらない場合
		for (auto i : (*stage_)) {
			if (CheckY(num, i) != 0) {
				Hit(CheckY(num, i), i);//Hitした時のプレイヤーの位置を調整する
				hit = true;
				break;
			}
		}
	}
	//マップ外に移動してしまうか確認する処理
	if (!hit) {//移動先に何もオブジェクトがなく、マップ外に移動しない場合
		y_ += num;
		player_state_ = Player_Air;//yがプレイヤーの状態を空中にいる状態にする
	}
}
//このオブジェクトを持ち上げられるかをチェックする
bool Player::CanPicked(const Object * object) {
	bool can_picked = true;
	for (auto i : (*stage_)) {
		if (Object::Check(object->x_ - width_, object->y_ - height_, i) != 0) {
			can_picked = false;
			break;
		}
	}
	return can_picked;
}
//このオブジェクトが持ち上げられるときの関数(未実装)
void Player::Picked(Object *object) {
}
//クリアしたときの関数
void Player::Clear() {
	player_state_ = Player_Clear;
}
//リトライしたときの関数
void Player::Retry() {
	Object::Retry();
	player_state_ = Player_Air;
	is_carrier_ = false;
	vector_ = 1;
}
//クリア出来るかを返す関数
// true:クリア可能,false:クリアできない
bool Player::CanClear() {
	bool canclear_ = true;
	if (player_state_ == Game_Clear) {//すでにクリアしている場合
		canclear_ = false;
	}
	return canclear_;
}