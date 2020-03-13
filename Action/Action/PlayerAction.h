#pragma once
#include "IActionBase.h"
#include "Player.h"
#include "Collision.h"
#include "PlayerHit.h"

class Player;
class PlayerHit;
//Playerの行動を担当する抽象クラス
class PlayerAction : public IActionBase {
protected:
	Player *player_;//行動するプレイヤー
public:
	PlayerAction(Player *player);
	//virtual void Do() = 0;
};