#pragma once
#include "ItemAction.h"
#include "Gravity.h"

//Item���d�͂��󂯂Ă���ۂɍs�����N���X
class ItemGravity :public ItemAction, Gravity {
protected:
	void MoveY(float num);
public:
	ItemGravity(Collision* collision, Item* item, Sound* sound);
	void Do()final;
};