#pragma once
#include "PlayerMoveX.h"

//Player�̉E�ړ���S��������N���X
class PlayerMoveRight : public PlayerMoveX {
public:
	PlayerMoveRight(Sound* sound, Collision *collision, Player *player,PlayerHit* hit);
	void Do() final;
};