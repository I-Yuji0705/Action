#pragma once
#include "ItemAction.h"
#include "Gravity.h"

//Itemが重力を受けている際に行う基底クラス
class ItemGravity :public ItemAction, Gravity {
protected:
	void MoveY(float num);
public:
	ItemGravity(Collision* collision, Item* item, Sound* sound);
	void Do()final;
};