#include "PlayerGravity.h"


PlayerGravity::PlayerGravity(Sound* sound, Collision *collision, Player *player, PlayerHit* playerhit)  : PlayerMoveY(sound, collision, player,playerhit){
}
void PlayerGravity::Do() {
	MoveY(gravity_.kGravity);
}