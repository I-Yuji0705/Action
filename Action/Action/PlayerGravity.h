#pragma once
#include "Gravity.h"
#include "PlayerMoveY.h"

//Player‚Ìd—Í(‰º•ûŒü)ˆÚ“®‚ğ’S“–‚·‚éŠî’êƒNƒ‰ƒX
class PlayerGravity : public PlayerMoveY, public Gravity {
public:
	PlayerGravity(Collision *collision, Player *player, Sound* sound);
	void Do() final;
};
