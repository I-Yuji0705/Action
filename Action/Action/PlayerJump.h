#pragma once
#include "PlayerMoveY.h"

//Player‚ÌJump(ã•ûŒü)ˆÚ“®‚ğ’S“–‚·‚éŠî’êƒNƒ‰ƒX
class PlayerJump : public PlayerMoveY {
private:
	const float kJumpPower = 8.0f;//Jump‚ÌŠî‘b‘¬“x
public:
	PlayerJump(Sound* sound, Collision *collision, Player *player,PlayerHit* hit);
	void Do() final;
};
