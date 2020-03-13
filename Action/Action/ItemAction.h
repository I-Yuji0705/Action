#pragma once
#include "IActionBase.h"
#include "Item.h"
#include "ItemHit.h"

class Item;
class ItemHit;

//Item‚Ìs“®‚ğ’S“–‚·‚é’ŠÛƒNƒ‰ƒX
class ItemAction : public IActionBase {
protected:
	Item *item_;
public:
	ItemAction(Item *item);
	//virtual void Do() override = 0;
};