#pragma once
#include "PlayerAction.h"

//Player‚Ì“Š‚°‚éˆ—‚ğ’S“–‚·‚éŠî’êƒNƒ‰ƒX
class PlayerThrow : public PlayerAction {
public:
	PlayerThrow(Collision *collision, Player *player, Sound* sound);
	void Do() final;
};