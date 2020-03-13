#pragma once
#include "PlayerMoveX.h"

//Player‚Ì‰EˆÚ“®‚ð’S“–‚·‚éŠî’êƒNƒ‰ƒX
class PlayerMoveRight : public PlayerMoveX {
public:
	PlayerMoveRight(Sound* sound, Collision *collision, Player *player,PlayerHit* hit);
	void Do() final;
};