#pragma once
#include "ItemAction.h"
#include "Gravity.h"

class Sound;
class Collision;
class ItemHit;

//Item���d�͂��󂯂Ă���ۂɍs�����N���X
class ItemMoveY :public ItemAction {
protected:
	Sound* sound_;
	Gravity gravity_;
	Collision* collision_;
	ItemHit* itemhit_;
	void MoveY(float num);
public:
	ItemMoveY(Sound* sound, Collision *collision, Item *item,ItemHit* itemhit);
	void Do()final;
};