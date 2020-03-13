#pragma once
#include "PlayerAction.h"

//Player‚ÌE‚¤ˆ—‚ğ’S“–‚·‚éŠî’êƒNƒ‰ƒX
class PlayerPick : public PlayerAction {
public:
	PlayerPick(Collision *collision, Player *player, Sound* sound);
	void Do() final;
};