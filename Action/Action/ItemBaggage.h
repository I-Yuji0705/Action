#pragma once
#include "ItemAction.h"

//Item��Player�Ɏ�����Ă���ۂɍs�����N���X
class ItemBaggage : public ItemAction {
public:
	ItemBaggage(Item *item);
	void Do() final;
};