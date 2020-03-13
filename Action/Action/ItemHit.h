#pragma once
#include "Hit.h"
#include "Item.h"

class Item;

//Itemが他のオブジェクトに接触した時の操作を担当する基底クラス
class ItemHit : public Hit {
private:
	Item* item_;
public:
	ItemHit(Collision* collision,Item* item);
	void HitObjects(int check, float distance)final;
};