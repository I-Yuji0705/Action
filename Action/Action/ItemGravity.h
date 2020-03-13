#pragma once
#include "ItemAction.h"
#include "Gravity.h"

//Item���d�͂��󂯂Ă���ۂɍs�����N���X
class ItemGravity :public ItemAction {
protected:
	Sound* sound_;
	Gravity gravity_;
	Collision* collision_;
	ItemHit* itemhit_;
	void MoveY(float num);
public:
	ItemGravity(Sound* sound, Collision *collision, Item *item,ItemHit* itemhit);
	void Do()final;
};