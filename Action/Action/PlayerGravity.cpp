#include "PlayerGravity.h"


PlayerGravity::PlayerGravity(Collision *collision, Player *player, Sound* sound)  : PlayerMoveY(collision,player,sound){
}
void PlayerGravity::Do() {
	MoveY(kGravity);
}