#pragma once
#include "ItemAction.h"

//Item���������n�߂��ۂ̍s���̊��N���X
class ItemStartThrow : public ItemAction {
public:
	ItemStartThrow(Item *item);
	void Do()final;
};