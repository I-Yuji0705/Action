#pragma once
#include "ActionBase.h"
#include "Player.h"
#include "Collision.h"
#include "PlayerHit.h"

class Player;
class PlayerHit;
//Playerの行動を担当する抽象クラス
class PlayerAction : public ActionBase {
protected:
	Player *player_;//行動するプレイヤー
	PlayerHit *playerhit_;
public:
	PlayerAction(Collision *collision, Player *player, Sound* sound);
	//virtual void Do() = 0;
};