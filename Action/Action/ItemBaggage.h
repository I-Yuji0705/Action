#pragma once
#include "ItemAction.h"

//ItemがPlayerに持たれている際に行う基底クラス
class ItemBaggage : public ItemAction {
public:
	ItemBaggage(Item *item);
	void Do() final;
};