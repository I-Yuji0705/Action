#pragma once
#include "PlayerMoveX.h"

//Player‚Ì¶ˆÚ“®‚ğ’S“–‚·‚éŠî’êƒNƒ‰ƒX
class PlayerMoveLeft : public PlayerMoveX {
public:
	PlayerMoveLeft(Collision *collision, Player *player, Sound* sound);
	void Do() final;
};