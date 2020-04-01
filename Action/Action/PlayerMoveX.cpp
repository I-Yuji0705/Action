#include "PlayerMoveX.h"
#include <tuple>
#include "DxLib.h"
#include "Keyboard.h"
#include <vector>
#include <algorithm>
#include "VectorNoduplicationInsert.h"

///<summary>
///<para>コンストラクタ</para>
///<para>キーが押されているか確認するKeyboardクラス、動作時に音を発生させるクラス、移動先に他のObjectがないか確認するクラス、接触処理を行うクラスを追加で取得する</para>
///<para>引数:</para>
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
///<para>引数:</para>
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
		player_->carryon_->Update();
		float carryondistance;
		std::vector<Object*> carryonhitobjects;
		int carryonhitpoint;
		std::tie(carryonhitpoint, carryondistance, carryonhitobjects) = collision_->HitCheckX(num, player_->carryon_);//背負っている物の当たり判定をチェックする
		if (!carryonhitobjects.empty() && carryonhitpoint != 0) {
			hitpoint = carryonhitpoint;
			hitobjects = VectorNoDuplicationInsert(hitobjects, carryonhitobjects);
			if (distance == 999.0f || (std::abs(distance) > std::abs(carryondistance) && carryondistance != 0))
				distance = carryondistance;
		}
	}
	if (hitpoint != 0 && !hitobjects.empty()) {//当たったObjectがあったか
		if(!Push(num, hitobjects, hitpoint))//オブジェクトを押す
			playerhit_->HitObjects(hitpoint, distance);//Hitした時のプレイヤーの位置を調整する
		if (firsthit_) {//Objectに接触し始めたとき
			sound_->PlaySe(Se_Hit, player_);
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
			sound_->PlaySe(Se_Hit, player_);
		}
	}
	if (!hit) {//移動先に何もオブジェクトがなく、マップ外に移動しない場合
		player_->x_ += num;
		firsthit_ = true;
	}
}
///<summary>
///<para>Playerの押す処理</para>
///<para>地面にいるときにのみ、押す動作を開始する</para>
///<para>渡された動的配列のから、Playerに密着しているObjectと、</para>
///<para>Playerに密着していないObjectの内、Playerから近いObjectとの差を得する</para>
///<para>PlayerがObjectを持っている場合、同様に密着しているObjectと密着していないObjectとの差を取得する</para>
///<para>密着しているObjectに、渡されたfloatの値に対して、どの程度動けるかを取得する</para>
///<para>収得した値のうち、一番小さい値でPlayerに密着しているObject全てを押す</para>
///<para>実際に押せたかどうかを戻り値にする</para>
///<para>引数:</para>
///<param name="num"><para>num:X軸に加算しようとしている値</para></param>
///<param name="target"><para>target:押そうとしている対象のObjectのポインタ全て</para></param>
///<param name="check"><para>check:Collision::HitCheckXでのint型の戻り値、押そうとしている方向を確認する</para></param>
///<returns>
///<para>true:少しでも押すことができた</para>
///<para>false:少しも押せなかった</para>
///</returns>
///</summary>
bool PlayerMoveX::Push(float num, std::vector<Object*> target, int check) {
	bool push = false;
	if (player_->player_state_ == Player_Land) {//地上にいるとき
		float canpushed;
		std::vector<Object*> pushtarget;
		std::tie(pushtarget, canpushed) = collision_->AlignAdhesionObjects(target, player_, check);
		if (player_->carryon_ != nullptr) {
			float carryoncanpushed;
			std::vector<Object*> carryonpushtarget;
			std::tie(carryonpushtarget, carryoncanpushed) = 
				collision_->AlignAdhesionObjects(target, player_->carryon_, check);
			if (!carryonpushtarget.empty()) {
				pushtarget = VectorNoDuplicationInsert(pushtarget, carryonpushtarget);
				if ((std::abs(canpushed) > std::abs(carryoncanpushed) && carryoncanpushed != 0))
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
				if (player_->carryon_ != nullptr)
					player_->carryon_->Update();
			}
		}
	}
	return push;
}