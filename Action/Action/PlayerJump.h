#pragma once
#include "PlayerMoveY.h"

//Player��Jump(�����)�ړ���S��������N���X
class PlayerJump : public PlayerMoveY {
private:
	const float kJumpPower = 8.0f;//Jump���̊�b���x
public:
	PlayerJump(Collision *collision, Player *player, Sound* sound);
	void Do() final;
};
