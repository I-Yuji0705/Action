#pragma once
#include "PlayerAction.h"

//Player�̃N���A���̃_���X�s����S��������N���X
class PlayerDance : public PlayerAction {
private:
	int dancetimer_, choreographnum_;
	void NextChoreoGrap();
public:
	PlayerDance(Player *player);
	void Do() final;
};