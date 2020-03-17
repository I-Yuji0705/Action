#pragma once
#include "ItemAction.h"
#include "Gravity.h"

class Sound;
class Collision;
class ItemHit;

//Itemが重力を受けている際に行う基底クラス
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