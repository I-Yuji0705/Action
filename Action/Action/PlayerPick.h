#pragma once
#include "PlayerAction.h"

//Player�̏E��������S��������N���X
class PlayerPick : public PlayerAction {
public:
	PlayerPick(Collision *collision, Player *player, Sound* sound);
	void Do() final;
};