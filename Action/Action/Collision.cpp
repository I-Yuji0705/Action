#include "Collision.h"
#include <vector>
#include <typeinfo>
#include "Player.h"

//Stageと、右端の地形と左端の地形の習得
Collision::Collision(std::vector<Object*> stage) {
	stage_ = stage;
	//ステージ端にある地形の検索
	map_left_, map_right_ = nullptr;
	for (auto i : stage_) {
		if (typeid(*i) == typeid(Terrain)) {
			if (map_left_ == nullptr) map_left_ = i;
			else if (map_left_->Left() > i->Left()) map_left_ = i;
			if (map_right_ == nullptr) map_right_ = i;
			else if (map_right_->Right() < i->Right()) map_right_ = i;
		}
	}
}

//対象のオブジェクトが指定した座標上に出る場合、
//指定したObjectに接触するかを返す
//引数:
//		x:対象のObjectが移動するX座標
//		y:対象のObjectが移動するY座標
//		player:対象のObject
//		object:調べるObject
//返り値:
//		true:Objectが接触する
//		false:Objectが接触しない
bool Collision::Check(float x, float y,const Object* player, const Object* object) {
	bool check = false;
	if (Check(x,y,x + player->GetWidth(), y + player->GetHeight(),player,object))
		check = true;
	return check;
}

bool Collision::Check(float x1, float y1, float x2, float y2,
	const Object* player,const Object* object) {
	bool check = false;
	if (object->quality_ && object != player &&
		y1  < object->Base() && object->Top() < y2 &&
		x1 < object->Right() && object->Left() < x2)
		check = true;
	return check;
}
//対象のオブジェクトが指定した座標上に出る場合、
//接触するObjectが存在するかどうか返す
//引数:
//		x:対象のObjectが移動するX座標
//		y:対象のObjectが移動するY座標
//		player:対象のObject
//返り値:
//		true:Objectが接触する
//		false:Objectが接触しない
bool Collision::Check(float x, float y, const Object* player) {
	bool check = false; 
	for (auto i : stage_) {
		if (i != player && i->quality_ &&
			Check(x , y , player, i)) {
			check = true;
			break;
		}
	}
	return check;
}
//Objectがnum地点に移動した場合、ステージの外に出るかどうかを返す
//引数:
//		num:objectの移動地点
//		object:判定を行うObject
//返り値:
//		0:ステージの外には出ない
//		1:ステージの右側から外に出る
//		2:ステージの左側から外に出る
int Collision::MapCheck(float num,const Object* player) {
	int check = 0;
	if (num + player->GetWidth() > map_right_->Right()) check = 1;
	else if (num < map_left_->Left()) check = 2;
	return check;
}
//-------------
//選択した引数の座標地点にObjectがあるかどうか、あった場合はy座標からどの程度の高さかを返す
//	引数:
//		x:座標のx地点
//		y:座標のy地点
//		player:検索の対象外にするObject
//	返り値:
//		0:Objectは存在しなかった。
//		0以外:引数のyから座標地点にあったObjectの底辺までの長さ
int Collision::PointCheck(float x, float y,const Object *player) {
	int length_y = 0;
	Object* object = nullptr;
	for (auto i : stage_) {
		if (i != player &&
			i->Left() <= x && x <= i->Right() &&
			i->Top() <= y && y <= i->Base()) {
			object = i;//長さを収得するObjectをセット
			break;
		}
	}
	if (object != nullptr) {
		length_y = (int)(object->Base() - y);//y地点からObjectの底辺までの距離
	}
	return length_y;
}

//-------------
//選択したObjectの内部すべてに他のObjectが存在するかを返す関数
//	引数:
//		area:調べるObject
//	返り値:
//		true:area内部のほぼ全てにオブジェクトが存在する
//		false:area内部にオブジェクトが存在していない隙間があった
bool Collision::AreaFullCheck(const Object* area) {
	bool check = true;
	const int permissibleLength = 5;//多少外側からずれてても大丈夫な長さ
	for (int i = (int)area->Left() + permissibleLength; i < (int)area->Right() - permissibleLength; i++) {
		for (int j = (int)area->Top() + permissibleLength; j < (int)area->Base() - permissibleLength; j++) {
			if (PointCheck((float)i, (float)j, area) == 0) {
				check = false;
				break;
			}
			else {
				j += PointCheck((float)i, (float)j, area);
			}
		}
	}
	return check;
}
//-------------
//選択した範囲内に他のObjectが存在するかを返す関数
//	引数:
//		target:結果を格納するObject
//		x1:範囲内の右上のX座標
//		y1:範囲内の右上のY座標
//		x2:範囲内の左下のX座標
//		y2:範囲内の左下のY座標
//		player:検索の対象外にするObject
//	返り値:
//		nullptr:接触したObjectは無い
//		nullptr以外:接触したObjectのポインタ
Object* Collision::AreaCheck(Object* target, float x1, float y1, float x2, float y2, const Object* player) {
	target = nullptr;
	for (auto i : stage_) {//ステージ上のオブジェクトから検索
		if (Check(x1,y1,x2,y2,player,i) &&//
			(target == nullptr ||
				abs(player->x_ - i->x_) <= abs(player->x_ - target->x_) &&
				//(abs(player->x_ - i->x_) == abs(player->x_ - target->x_) &&
				(i->Base() < target->Base()))) {
			target = i;//持ち上げる対象を設定する
		}
	}
	return target;
}

//-------------
//ステージの左端にある地形を返す
//	引数:
//		target:結果を格納するObject
//	返り値:
//		ステージの左端にある地形を返す
Object* Collision::GetMapLeft(Object* target) {
	target = map_left_;
	return target;
}

//-------------
//ステージの右端にある地形を返す
//	引数:
//		target:結果を格納するObject
//	返り値:
//		ステージの左端にある地形を返す
Object* Collision::GetMapRight(Object* target) {
	target = map_right_;
	return target;
}

//-------------
//ステージ上にあるPlayer全てを返す
//	返り値:
//		ステージ上にあるPlayer全てを返す
std::vector<Object*> Collision::GetPlayer() {
	std::vector<Object*> players;
	for (auto i: stage_) {
		if (typeid(*i) == typeid(Player)) {
			players.push_back(i);
		}
	}
	return players;
}
//PlayerがX軸にnumを追加した結果、objectに接触するか、した場合にはどの部分に接触したかを返す
//引数:
//		num:X軸に加算する数字(移動する距離)
//		object:接触するか判定を行うObject
//返り値:
//	int:
//		0:接触なし
//		1:objectの左側に接触
//		2:objectの右側に接触
//	Object*:
//		nullptr:接触したObjectは無い
//		nullptr以外:接触したObjectのポインタ
std::tuple<int, std::vector<Object *>> Collision::HitCheckX(float num, const Object* player) {
	int check = 0;
	std::vector<Object*> hitobject;
	for (auto i : stage_) {
		if (i != player && i->quality_ &&
			Check(player->Left() + num, player->Top(), player, i)) {
			hitobject.push_back(i);
			if (num > 0) check = 1;//地形の上側から衝突した時
			else check = 2;//地形の下から衝突した時
		}
	}
	return std::forward_as_tuple(check, hitobject);
}
//PlayerがX軸にnumを追加した結果、objectに接触するか、した場合にはどの部分に接触したかを返す
//引数:
//		num:Y軸に加算する数字(移動する距離)
//		object:接触するか判定を行うObject
//返り値:
//	int:
//		0:接触なし
//		3:objectの上側に接触
//		4:objectの下側に接触
//	Object*:
//		nullptr:接触したObjectは無い
//		nullptr以外:接触したObjectのポインタ
std::tuple<int, std::vector<Object *>> Collision::HitCheckY(float num, const Object* player) {
	int check = 0;
	std::vector<Object*> hitobject;
	for (auto i : stage_) {
		if (i != player && i->quality_ &&
			Check(player->Left(), player->Top() + num, player, i)) {
			hitobject.push_back(i);
			if (num > 0) check = 3;//地形の上側から衝突した時
			else check = 4;//地形の下から衝突した時
			break;
		}
	}
	return std::forward_as_tuple(check, hitobject);
}