#include "PlayerMoveRight.h"


PlayerMoveRight::PlayerMoveRight(Sound* sound, Collision *collision, Player *player, PlayerHit* playerhit) : PlayerMoveX(sound, collision, player,playerhit){
}
void PlayerMoveRight::Do() {
	player_->vector_ = 1;
	MoveX(kMoveSpeed);
}