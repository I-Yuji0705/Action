#pragma once
#include "PlayerMoveX.h"

//Player�̉E�ړ���S��������N���X
class PlayerMoveRight : public PlayerMoveX {
public:
	PlayerMoveRight(Collision *collision, Player *player, Sound* sound);
	void Do() final;
};