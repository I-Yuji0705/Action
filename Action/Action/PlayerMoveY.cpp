#include "PlayerMoveY.h"
#include <tuple>

PlayerMoveY::PlayerMoveY(Collision *collision, Player *player, Sound* sound) : PlayerAction(collision, player, sound) {
}
void PlayerMoveY::MoveY(float num) {
	//プレイヤーのX軸の移動を行う
	bool hit = false;
	int hitpoint;
	std::vector<Object*> hitobject;
	std::tie(hitpoint, hitobject) = collision_->HitCheckY(num, player_);
	if (hitpoint != 0 && !hitobject.empty() && *hitobject.begin() != player_->carryon_) {
		playerhit_->HitProcess(hitpoint, *hitobject.begin());//Hitした時のプレイヤーの位置を調整する
		hit = true;
		if(num < 0) sound_->PlaySe(Se_Hit, player_);
	}
	if (!hit && player_->carryon_ != nullptr) {//何か背負っているとき
		player_->carryon_->Update();
		std::tie(hitpoint, hitobject) = collision_->HitCheckY(num, player_->carryon_);//背負っている物の当たり判定をチェックする
		if (hitpoint != 0 && !hitobject.empty() && *hitobject.begin() != player_) {
			playerhit_->HitProcess(hitpoint, *hitobject.begin(),player_->carryon_);//Hitした時のプレイヤーの位置を調整する
			hit = true;
			if (num < 0) sound_->PlaySe(Se_Hit, player_);
		}
	}
	if (!hit) {
		player_->y_ += num;
		player_->player_state_ = Player_Air;
	}
}