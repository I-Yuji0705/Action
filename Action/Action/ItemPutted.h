#pragma once
#include"ItemAction.h"

//Item���u�����ۂɍs���s���̊��N���X
class ItemPutted : public ItemAction {
public:
	ItemPutted(Item *item);
	void Do() final;
};