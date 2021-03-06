#pragma once
#include "IActionBase.h"
#include "Item.h"
#include "ItemHit.h"

class Item;

//Itemの行動を担当する抽象クラス
class ItemAction : public IActionBase {
protected:
	Item *item_;
public:
	ItemAction(Item *item);
};