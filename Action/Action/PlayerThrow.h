#pragma once
#include "PlayerAction.h"

//Player�̓����鏈����S��������N���X
class PlayerThrow : public PlayerAction {
public:
	PlayerThrow(Collision *collision, Player *player, Sound* sound);
	void Do() final;
};