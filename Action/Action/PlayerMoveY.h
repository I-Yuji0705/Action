#pragma once
#include "PlayerAction.h"

//Player��Y���̈ړ���S�����钊�ۃN���X
class PlayerMoveY : public PlayerAction {
protected:
	void MoveY(float num);
public:
	PlayerMoveY(Collision *collision, Player *player, Sound* sound);
	//void Do() override = 0;
};