#include "PlayerMoveX.h"
#include <tuple>
#include "DxLib.h"
#include "Keyboard.h"
#include <vector>
#include <algorithm>
#include "VectorFunctions.h"

///<summary>
///<para>コンストラクタ</para>
///<para>キーが押されているか確認するKeyboardクラス、動作時に音を発生させるクラス、移動先に他のObjectがないか確認するクラス、接触処理を行うクラスを追加で取得する</para>
///<param name= "keyboard"><para>キーが押されているか確認するクラス</para></param>
///<param name= "sound"><para>動作時に音を発生させるクラス</para></param>
///<param name= "collision"><para>拾う範囲に他のObjectがないか確認するクラス</para></param>
///<param name= "playerhit"><para>Playerの接触処理を行うクラス</para></param>
///</summary>
PlayerMoveX::PlayerMoveX(Keyboard* keyboard,Sound* sound, Collision *collision, Player *player, PlayerHit* playerhit) : PlayerAction(player) {
	keyboard_ = keyboard;
	sound_ = sound;
	collision_ = collision;
	playerhit_ = playerhit;
	firsthit_ = true;
}

///<summary>
///<para>行動処理</para>
///<para>キーボードの左右キーの入力状態を確認し、移動を行う。</para>
///<para>左キーのみを押している場合は、左移動する。</para>
///<para>右キーのみを押している場合は、右移動する。</para>
///</summary>
void PlayerMoveX::Do() {
	if (keyboard_->CheckKey(KEY_INPUT_LEFT) != 0 && //左キーが押されており、
		keyboard_->CheckKey(KEY_INPUT_RIGHT) == 0) { //右キーが押されていなかったら
		player_->vector_ = -1;
		MoveX(-kMoveSpeed);
	}
	if (keyboard_->CheckKey(KEY_INPUT_RIGHT) != 0 && //右キーが押されており、
		keyboard_->CheckKey(KEY_INPUT_LEFT) == 0) { //左キーが押されていなかったら
		player_->vector_ = 1;
		MoveX(kMoveSpeed);
	}
}

///<summary>
///<para>X軸の移動処理</para>
///<para>移動しようとしている数字を受け取り、移動先に他のObjectに接触するかを調べる</para>
///<para>移動先にObjectない場合:xに数値を加算し、移動する</para>
///<para>移動先にObjectある場合:対象のObjectを押し、少しも押せなかったら接触処理を行う</para>
///<para>PlayerがObjectを持っている場合、そのObjectも同様に接触するかを調べる</para>
///<param name="num"><para>num:X軸に加算しようとしている値</para></param>
///</summary>
void PlayerMoveX::MoveX(float num) {
	//プレイヤーのX軸の移動を行う
	bool hit = false;
	int hitpoint;
	float distance;
	std::vector<Object*> hitobjects;
	std::tie(hitpoint, distance, hitobjects) = collision_->HitCheckX(num, player_);//移動した際に当たるオブジェクトと当たる場所の算出
	if (player_->carryon_ != nullptr) {
		//player_->carryon_->Update();
		float carryondistance;
		std::vector<Object*> carryonhitobjects;
		int carryonhitpoint;
		std::tie(carryonhitpoint, carryondistance, carryonhitobjects) = collision_->HitCheckX(num, player_->carryon_);//背負っている物の当たり判定をチェックする
		if (!carryonhitobjects.empty() && carryonhitpoint != 0) {
			hitpoint = carryonhitpoint;
			hitobjects = VectorNoDuplicationInsert(hitobjects, carryonhitobjects);
			if ((std::abs(distance) > std::abs(carryondistance)))
				distance = carryondistance;
		}
	}
	if (hitpoint != 0 && !hitobjects.empty()) {//当たったObjectがあったか
		playerhit_->HitObjects(hitpoint, distance);//Hitした時のプレイヤーの位置を調整する
		Push(num, hitobjects, hitpoint);//オブジェクトを押す
		if (firsthit_) {//Objectに接触し始めたとき
			sound_->PlaySe(Se_Name::Se_Hit, player_);
			firsthit_ = false;
		}
		hit = true;
	}
	std::tie(hitpoint,distance)= collision_->MapCheck(player_->Left() + num, player_);
	if (hitpoint != 0) {//マップ外に移動してしまうか確認する処理
		playerhit_->HitObjects(hitpoint,distance);
		hit = true;
		if (firsthit_) {
			firsthit_ = false;
			sound_->PlaySe(Se_Name::Se_Hit, player_);
		}
	}
	if (!hit) {//移動先に何もオブジェクトがなく、マップ外に移動しない場合
		player_->x_ += num;
		firsthit_ = true;
	}
	if (player_->carryon_ != nullptr)
		player_->carryon_->Update();
}

//バグ：
//Playerと横幅が違うItemを持った状態で複数のItemに接触し、接触したItemが他のItemを押し始めるとStack Overflowで強制終了する

///<summary>
///<para>Playerの押す処理</para>
///<para>地面にいるときにのみ、押す動作を開始する</para>
///<para>渡された動的配列のから、Playerに密着しているObjectと、</para>
///<para>Playerに密着していないObjectの内、Playerから近いObjectとの差を得する</para>
///<para>PlayerがObjectを持っている場合、同様に密着しているObjectと密着していないObjectとの差を取得する</para>
///<para>密着しているObjectに、渡されたfloatの値に対して、どの程度動けるかを取得する</para>
///<para>収得した値のうち、一番小さい値でPlayerに密着しているObject全てを押す</para>
///<para>実際に押せたかどうかを戻り値にする</para>
///<param name="num"><para>num:X軸に加算しようとしている値</para></param>
///<param name="target"><para>target:押そうとしている対象のObjectのポインタ全て</para></param>
///<param name="check"><para>check:Collision::HitCheckXでのint型の戻り値、押そうとしている方向を確認する</para></param>
///<returns><para>押すことが出来たか</para></returns>
///</summary>
void PlayerMoveX::Push(float num, std::vector<Object*> target, int check) {
	bool push = false;
	if (player_->player_state_ == StateCharacter::Player_Land) {//地上にいるとき
		float canpushed;
		std::vector<Object*> pushtarget;
		std::tie(pushtarget, canpushed) = AlignAdhesionObjects(target, player_, check);
		if (player_->carryon_ != nullptr) {
			float carryoncanpushed;
			std::vector<Object*> carryonpushtarget;
			std::tie(carryonpushtarget, carryoncanpushed) = 
				AlignAdhesionObjects(target, player_->carryon_, check);
			if (!carryonpushtarget.empty()) {
				pushtarget = VectorNoDuplicationInsert(pushtarget, carryonpushtarget);
				if (std::abs(canpushed) > std::abs(carryoncanpushed))
					canpushed = carryoncanpushed;
			}
		}
		if (!pushtarget.empty()) {
			for (auto i : pushtarget) {
				if (std::abs(canpushed) > std::abs(i->CanPushed(num))) {//
					canpushed = i->CanPushed(num);//押し出せる距離を算出
				}
			}
			if (canpushed != 0.0f) {
				for (auto i : pushtarget) {
					i->Pushed(canpushed);
				}
				push = true;
				player_->Set(player_->Left() + canpushed, player_->Top());
			}
		}
	}
}

///<summary>
///<para>Objectの動的配列から、対象のObjectに接触しているObjectの動的配列と</para>
///<para>接触しているObjectから、接触していないObjectのうち、一番近いObjectまでの差を返す</para>
///<param name="objects"><para>objects:調べるObjectのポインタの動的配列</para></param>
///<param name="player"><para>player:接触しているか調べるObjectのポインタ</para></param>
///<param name="check"><para>check:HitCheckX及びHitCheckYのintで返されるint型変数</para></param>
///<returns>
///<para>std::vector:接触ししている全てのObjectのポインタ</para>
///<para>float:Pushで移動する初期値</para>
///</returns>
///</summary>
std::tuple<std::vector<Object*>, float>PlayerMoveX::AlignAdhesionObjects(std::vector<Object*>objects, const Object* player,
	int check) {
	std::vector<Object*> adhesionobjects;
	float distance = 999.0f;
	for (auto i : objects) {
		float objectdistance = collision_->ObjectDistance(i, player, check);//対象との距離を習得する
		if (objectdistance == 0.0f) {//playerと密着している場合
			adhesionobjects.push_back(i);//押す対象に追加する
		}
		else if (((check == 1 && objectdistance > 0.0f) || (check == 2 && objectdistance < 0.0f)) && //移動先にあり、
			std::abs(distance) > std::abs(objectdistance)) {//他よりも近い場合、
			distance = objectdistance;//値を更新する
		}
	}
	return std::forward_as_tuple(adhesionobjects, distance);
}