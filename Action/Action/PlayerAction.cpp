#include "PlayerAction.h"

//Player�̍s���̒��ۃN���X
PlayerAction::PlayerAction(Collision * collision, Player *player, Sound* sound) : ActionBase(collision,sound) {
	player_ = player;
	playerhit_ = new PlayerHit(collision,player_);
}