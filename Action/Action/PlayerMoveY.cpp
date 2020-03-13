#include "PlayerMoveY.h"
#include <tuple>

PlayerMoveY::PlayerMoveY(Sound* sound, Collision *collision, Player *player, PlayerHit* playerhit) : PlayerAction(player) {
	sound_ = sound;
	collision_ = collision;
	playerhit_ = playerhit;
}
void PlayerMoveY::MoveY(float num) {
	//プレイヤーのX軸の移動を行う
	bool hit = false;
	int hitpoint;
	float distance;
	std::vector<Object*> hitobjects; 
	if (player_->carryon_ != nullptr) {//何か背負っているとき
		player_->carryon_->Update();
		std::tie(hitpoint, distance, hitobjects) = collision_->HitCheckY(num, player_->carryon_);//背負っている物の当たり判定をチェックする
		if (hitpoint != 0 && !hitobjects.empty() &&
			*hitobjects.begin() != player_) {//当たったObjectがあったか
			std::tie(hitobjects, distance) = collision_->AlignAdhesionObjects(hitobjects, player_->carryon_, hitpoint);
			if (distance != 999.0f)
				playerhit_->HitObjects(hitpoint, distance);//Hitした時のプレイヤーの位置を調整する
			if (distance != 0.0f && distance != 999.0f)
				sound_->PlaySe(Se_Hit, player_);
			hit = true;
		}
	}
	std::tie(hitpoint, distance, hitobjects) = collision_->HitCheckY(num, player_);//移動した際に当たるオブジェクトと当たる場所の算出
	if (hitpoint != 0  && !hitobjects.empty() && 
		*hitobjects.begin() != player_->carryon_) {//当たったObjectがあったか
		playerhit_->HitObjects(hitpoint, distance);//Hitした時のプレイヤーの位置を調整する
		if(distance != 0.0f)
			sound_->PlaySe(Se_Hit, player_);
		hit = true;
	}
	if (!hit) {
		player_->y_ += num;
		player_->player_state_ = Player_Air;
	}
}