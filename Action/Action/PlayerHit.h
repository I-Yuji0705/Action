#pragma once
#include "Player.h"
#include "Hit.h"

class Player;
//Playerが他のObject接触を行った時の処理を担当する基底クラス
class PlayerHit : public Hit{
protected:
	Player* player_;
public:
	PlayerHit(Collision* collision,Player* player);
	void HitObjects(int check, float distance);
};