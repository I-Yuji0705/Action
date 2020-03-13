#include "PlayerAction.h"

//Player‚Ìs“®‚Ì’ŠÛƒNƒ‰ƒX
PlayerAction::PlayerAction(Collision * collision, Player *player, Sound* sound) : ActionBase(collision,sound) {
	player_ = player;
	playerhit_ = new PlayerHit(collision,player_);
}