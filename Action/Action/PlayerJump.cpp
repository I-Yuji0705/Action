#include "PlayerJump.h"


PlayerJump::PlayerJump(Collision *collision, Player *player, Sound* sound) : PlayerMoveY(collision, player,sound) {
}
void PlayerJump::Do() {
	if(player_->angle_ == 0) sound_->PlaySe(Se_Jump, player_);
	if (player_->angle_ > 90) player_->angle_ = 90;//ãƒL[‚ğ“ü—Í‚µ‘±‚¯‚Ä‚àcos(angle_ * 3.141592f * 1 / 120)‚ª0‚É‚È‚é‚æ‚¤‚É‚·‚é
	MoveY(-kJumpPower * (float)cos(player_->angle_ * 3.141592f * 1 / 120));
	player_->angle_++;//angle‚ğ‘‰Á‚µ‘±‚¯‚é
}