#pragma once
#include "PlayerMoveY.h"
#include "Gravity.h"
//Player�̏d��(������)�ړ���S��������N���X
class PlayerGravity : public PlayerMoveY {
public:
	PlayerGravity(Sound* sound, Collision *collision, Player *player,PlayerHit* hit);
	void Do() final;
};
