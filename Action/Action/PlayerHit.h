#pragma once
#include "Player.h"
#include "Hit.h"

class Player;
//Player������Object�ڐG���s�������̏�����S��������N���X
class PlayerHit : public Hit{
protected:
	Player* player_;
public:
	PlayerHit(Collision* collision,Player* player);
	void HitObjects(int check, float distance);
};