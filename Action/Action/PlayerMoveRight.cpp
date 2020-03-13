#include "PlayerMoveRight.h"


PlayerMoveRight::PlayerMoveRight(Collision *collision, Player *player, Sound* sound) : PlayerMoveX(collision,player,sound){
}
void PlayerMoveRight::Do() {
	player_->vector_ = 1;
	MoveX(kMoveSpeed);
}