#pragma once
#include "PlayerMoveX.h"

//Player‚Ì¶ˆÚ“®‚ğ’S“–‚·‚éŠî’êƒNƒ‰ƒX
class PlayerMoveLeft : public PlayerMoveX {
public:
	PlayerMoveLeft(Sound* sound, Collision *collision, Player *player,PlayerHit* hit);
	void Do() final;
};