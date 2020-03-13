#pragma once
#include "PlayerAction.h"

//Playerのクリア時のダンス行動を担当する基底クラス
class PlayerDance : public PlayerAction {
private:
	int dancetimer_, choreographnum_;
	void NextChoreoGrap();
public:
	PlayerDance(Player *player);
	void Do() final;
};