#pragma once
#include "ItemAction.h"

//Item��Player�Ɏ�����Ă���ۂɍs�����N���X
class ItemBaggage : public ItemAction {
public:
	ItemBaggage(Collision * collision, Item* item_, Sound* sound);
	void Do() final;
};