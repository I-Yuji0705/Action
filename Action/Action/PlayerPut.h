#pragma once
#include "PlayerAction.h"

//Player�̒u��������S��������N���X
class PlayerPut : public PlayerAction {
public:
	PlayerPut(Collision * collision, Player *player, Sound* sound);
	void Do() final;
};