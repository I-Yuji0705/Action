#pragma once
#include "PlayerAction.h"

class Keyboard;
//Player�̃N���A���̃_���X�s����S��������N���X
class PlayerInversion : public PlayerAction {
private:
	Keyboard* keyboard_;
public:
	PlayerInversion(Keyboard* keyboard,Player *player);
	void Do() final;
};