#pragma once
#include "PlayerMoveX.h"

//Player�̍��ړ���S��������N���X
class PlayerMoveLeft : public PlayerMoveX {
public:
	PlayerMoveLeft(Sound* sound, Collision *collision, Player *player,PlayerHit* hit);
	void Do() final;
};