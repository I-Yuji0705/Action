#pragma once
#include "PlayerMoveY.h"

//Player��Jump(�����)�ړ���S��������N���X
class PlayerJump : public PlayerMoveY {
private:
	const float kJumpPower = 8.0f;//Jump���̊�b���x
public:
	PlayerJump(Sound* sound, Collision *collision, Player *player,PlayerHit* hit);
	void Do() final;
};
