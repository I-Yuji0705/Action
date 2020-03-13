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
	void HitProcess(int hitcheck, Object* hitobject) final;
	void HitProcess(int hitcheck, Object* hitobject, Object* carrier);
	void MapHit(int mapcheck) final;
};