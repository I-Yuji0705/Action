#pragma once
#include"ItemAction.h"

//Item���u�����ۂɍs���s���̊��N���X
class ItemPutted : public ItemAction {
public:
	ItemPutted(Collision* collision, Item* item, Sound* sound);
	void Do() final;
};