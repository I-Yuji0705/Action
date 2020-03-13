#pragma once
#include "Player.h"
#include "Hit.h"

class Player;
//Player‚ª‘¼‚ÌObjectÚG‚ğs‚Á‚½‚Ìˆ—‚ğ’S“–‚·‚éŠî’êƒNƒ‰ƒX
class PlayerHit : public Hit{
protected:
	Player* player_;
public:
	PlayerHit(Collision* collision,Player* player);
	void HitObjects(int check, float distance);
};