#pragma once
#include "IActionBase.h"
#include "Item.h"
#include "ItemHit.h"

class Item;

//Item�̍s����S�����钊�ۃN���X
class ItemAction : public IActionBase {
protected:
	Item *item_;
public:
	ItemAction(Item *item);
};