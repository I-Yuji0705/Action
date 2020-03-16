#include "PlayerJump.h"
#include <cmath>

///<summary>
///<para>コンストラクタ</para>
///</summary>
PlayerJump::PlayerJump(Sound* sound, Collision *collision, Player *player, PlayerHit* playerhit) : PlayerMoveY(sound, collision, player,playerhit) {
}

void PlayerJump::Do() {
	if(player_->angle_ == 0) sound_->PlaySe(Se_Jump, player_);
	if (player_->angle_ > 60) player_->angle_ = 60;//上キーを入力し続けてもcos(90 * player_->angle_ / 60 * 3.141592f / 180)が0になるようにする
	if(std::abs(kJumpPower * (float)cos(90 * player_->angle_ / 60 * 3.141592f / 180)) > abs(gravity_.kGravity))
		MoveY(-kJumpPower * (float)cos(90 * player_->angle_ / 60  * 3.141592f / 180));
	player_->angle_++;//angleを増加し続ける
}