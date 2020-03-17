#pragma once
#include "PlayerAction.h"

class Keyboard;
//Playerのクリア時のダンス行動を担当する基底クラス
class PlayerInversion : public PlayerAction {
private:
	Keyboard* keyboard_;
public:
	PlayerInversion(Keyboard* keyboard,Player *player);
	void Do() final;
};