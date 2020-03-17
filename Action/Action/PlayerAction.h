#pragma once
#include "IActionBase.h"
#include "Player.h"
#include "Collision.h"

class Player;
//Playerの行動を担当する抽象クラス
//PlayerDanceを除き、Keyboardから入力を受け付け、対応した動作を行う
class PlayerAction : public IActionBase {
protected:
	Player *player_;//行動するプレイヤー
public:
	PlayerAction(Player *player);
	//virtual void Do() = 0;
};