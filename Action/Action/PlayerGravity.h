#pragma once
#include "PlayerMoveY.h"
#include "Gravity.h"
//Player‚Ìd—Í(‰º•ûŒü)ˆÚ“®‚ğ’S“–‚·‚éŠî’êƒNƒ‰ƒX
class PlayerGravity : public PlayerMoveY {
public:
	PlayerGravity(Sound* sound, Collision *collision, Player *player,PlayerHit* hit);
	void Do() final;
};
