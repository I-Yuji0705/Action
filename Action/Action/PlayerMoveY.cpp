#include "PlayerMoveY.h"
#include <tuple>
#include "DxLib.h"
#include "VectorFunctions.h"

///<summary>
///<para>コンストラクタ</para>
///<para>キーが押されているか確認するKeyboardクラス、動作時に音を発生させるクラス、移動先に他のObjectがないか確認するクラス、接触処理を行うクラスを追加で取得する</para>
///<param name= "keyboard"><para>キーが押されているか確認するクラス</para></param>
///<param name= "sound"><para>動作時に音を発生させるクラス</para></param>
///<param name= "collision"><para>拾う範囲に他のObjectがないか確認するクラス</para></param>
///<param name= "playerhit"><para>Playerの接触処理を行うクラス</para></param>
///</summary>
PlayerMoveY::PlayerMoveY(Keyboard* keyboard,Sound* sound, Collision *collision, Player *player, PlayerHit* playerhit) : PlayerAction(player) {
	keyboard_ = keyboard;
	sound_ = sound;
	collision_ = collision;
	playerhit_ = playerhit;
}

///<summary>
///<para>行動処理</para>
///<para>上キーを押した場合、ジャンプする</para>
///<para>押していない場合、または重力よりも上に上がる力がない場合、下に落下する</para>
///</summary>
void PlayerMoveY::Do() {
	float jumpdistance = 0.0f;
	if ((keyboard_->CheckKey(KEY_INPUT_UP) == 1 && player_->player_state_ == StateCharacter::Player_Land) ||//プレイヤーが地上にいるときか
		(keyboard_->CheckKey(KEY_INPUT_UP) > 1 && player_->angle_ != 0)) {//上キーを入力し続けているとき
		if (player_->angle_ == 0) sound_->PlaySe(Se_Name::Se_Jump, player_);
		if (player_->angle_ > 60) player_->angle_ = 60;//上キーを入力し続けてもcos(90 * player_->angle_ / 60 * 3.141592f / 180)が0になるようにする
		if (std::abs(kJumpPower * (float)cos(90 * player_->angle_ / 60 * 3.141592f / 180)) > abs(gravity_.kGravity))
			jumpdistance = -kJumpPower * (float)cos(90 * player_->angle_ / 60 * 3.141592f / 180);
		player_->angle_++;//angleを増加し続ける
	}
	else if (player_->angle_ != 0) {//上キーの入力をしていないとき、またはジャンプ中に入力をやめたとき
		player_->angle_ = 0;//angleを0に設定する
	}
	jumpdistance += gravity_.kGravity;
	MoveY(jumpdistance);
}

///<summary>
///<para>Y軸の移動処理</para>
///<para>移動しようとしている数字を受け取り、移動先に他のObjectに接触するかを調べる</para>
///<para>移動先またはPlayerが持っているObject以外にObjectがない場合:yに数値を加算し、空中に移動する</para>
///<para>移動先またはPlayerが持っているObject以外ににObjectがあった場合:接触処理を行う</para>
///<para>PlayerがObjectを持っている場合、そのObjectも同様にPlayer以外と接触するかを調べる</para>
///<param name="num"><para>num:X軸に加算しようとしている値</para></param>
///</summary>
void PlayerMoveY::MoveY(float num) {
	//プレイヤーのY軸の移動を行う
	bool hit = false;
	int hitpoint;
	float distance;
	std::vector<Object*> hitobjects; 
	float carryondistance;
	std::vector<Object*> carryonhitobjects;
	int carryonhitpoint;
	std::tie(hitpoint, distance, hitobjects) = collision_->HitCheckY(num, player_,player_->carryon_);//移動した際に当たるオブジェクトと当たる場所の算出
	if (player_->carryon_ != nullptr) {
		//auto carryon = std::find(hitobjects.begin(), hitobjects.end(), player_->carryon_);
		//if (carryon != hitobjects.end())
		//	hitobjects.erase(carryon);
		std::tie(carryonhitpoint, carryondistance, carryonhitobjects) = collision_->HitCheckY(num, player_->carryon_,player_);//背負っている物の当たり判定をチェックする
		//auto player = std::find(carryonhitobjects.begin(), carryonhitobjects.end(), player_);
		//if (player != carryonhitobjects.end())
		//	carryonhitobjects.erase(player);
		if (!carryonhitobjects.empty() && carryonhitpoint != 0) {
			hitpoint = carryonhitpoint;
			if ((std::abs(distance) > std::abs(carryondistance) /*&& carryondistance != 0.0f*/))
				distance = carryondistance;
		}
		hitobjects = VectorNoDuplicationInsert(hitobjects, carryonhitobjects);
	}
	if (hitpoint != 0 && !hitobjects.empty()) {//当たったObjectがあったか
			playerhit_->HitObjects(hitpoint, distance);//Hitした時のプレイヤーの位置を調整する
			if (distance != 0.0f || num < 0)
				sound_->PlaySe(Se_Name::Se_Hit, player_);
	}
	else {
		player_->y_ += num;
		player_->player_state_ = StateCharacter::Player_Air;
	}
	if (player_->carryon_ != nullptr)
		player_->carryon_->Update();
}