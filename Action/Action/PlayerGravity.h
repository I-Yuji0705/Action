#pragma once
#include "Gravity.h"
#include "PlayerMoveY.h"

//Player�̏d��(������)�ړ���S��������N���X
class PlayerGravity : public PlayerMoveY, public Gravity {
public:
	PlayerGravity(Collision *collision, Player *player, Sound* sound);
	void Do() final;
};
