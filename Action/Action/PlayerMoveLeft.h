#pragma once
#include "PlayerMoveX.h"

//Player�̍��ړ���S��������N���X
class PlayerMoveLeft : public PlayerMoveX {
public:
	PlayerMoveLeft(Collision *collision, Player *player, Sound* sound);
	void Do() final;
};