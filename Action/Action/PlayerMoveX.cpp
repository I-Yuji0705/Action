#include "PlayerMoveX.h"
#include <tuple>
#include "DxLib.h"
#include "Keyboard.h"
#include <vector>
#include <algorithm>
#include "VectorNoduplicationInsert.h"

PlayerMoveX::PlayerMoveX(Sound* sound, Collision *collision, Player *player, PlayerHit* playerhit) : PlayerAction(player) {
	sound_ = sound;
	collision_ = collision;
	playerhit_ = playerhit;
	firsthit_ = true;
}
//プレイヤーのX軸の移動を行う
//	引数:
//		num:移動しようする距離
void PlayerMoveX::MoveX(float num) {
	//プレイヤーのX軸の移動を行う
	bool hit = false;
	int hitpoint;
	float distance;
	std::vector<Object*> hitobjects;
	std::tie(hitpoint, distance, hitobjects) = collision_->HitCheckX(num, player_);//移動した際に当たるオブジェクトと当たる場所の算出
	if (player_->carryon_ != nullptr) {
		float carryondistance;
		std::vector<Object*> carryonhitobjects;
		int carryonhitpoint;
		std::tie(carryonhitpoint, carryondistance, carryonhitobjects) = collision_->HitCheckX(num, player_->carryon_);//背負っている物の当たり判定をチェックする
		if (!carryonhitobjects.empty() && carryonhitpoint != 0) {
			hitpoint = carryonhitpoint;
			hitobjects = VectorNoDuplicationInsert(hitobjects, carryonhitobjects);
			if (distance == 0 || (std::abs(distance) > std::abs(carryondistance) && carryondistance != 0))
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
				if (canpushed == 0 || (std::abs(canpushed) > std::abs(carryoncanpushed) && carryoncanpushed != 0))
					canpushed = carryoncanpushed;
			}
		}
		if (!pushtarget.empty()) {
			for (auto i : pushtarget) {
				if (std::abs(canpushed) > std::abs(i->CanPushed(num / 2))) {//
					canpushed = i->CanPushed(num / 2);//押し出せる距離を算出
				}
			}
			for (auto i : pushtarget) {
				i->Pushed(canpushed);
			}
			push = true;
			player_->Set(player_->Left() + canpushed, player_->Top());
		}
	}
	return push;
}