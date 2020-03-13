#pragma once
#include "PlayerAction.h"

//Player‚Ì’u‚­ˆ—‚ğ’S“–‚·‚éŠî’êƒNƒ‰ƒX
class PlayerPut : public PlayerAction {
public:
	PlayerPut(Collision * collision, Player *player, Sound* sound);
	void Do() final;
};