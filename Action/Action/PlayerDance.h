#pragma once
#include "PlayerAction.h"

//Player�̃N���A���̃_���X�s����S��������N���X
class PlayerDance : public PlayerAction {
private:
	int dancetimer_, choreographnum_;
	void NextChoreoGrap();
public:
	PlayerDance(Collision *collision, Player *player, Sound* sound);
	void Do() final;
};