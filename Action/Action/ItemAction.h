#pragma once
#include "ActionBase.h"
#include "Item.h"
#include "ItemHit.h"

class Item;
class ItemHit;

//Item�̍s����S�����钊�ۃN���X
class ItemAction : public ActionBase {
protected:
	Item *item_;
	ItemHit *itemhit_;
public:
	ItemAction(Collision *collision, Item *item,Sound* sound);
	//virtual void Do() override = 0;
};