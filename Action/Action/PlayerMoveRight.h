#pragma once
#include "PlayerMoveX.h"

//Player‚Ì‰EˆÚ“®‚ð’S“–‚·‚éŠî’êƒNƒ‰ƒX
class PlayerMoveRight : public PlayerMoveX {
public:
	PlayerMoveRight(Collision *collision, Player *player, Sound* sound);
	void Do() final;
};