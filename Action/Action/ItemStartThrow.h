#pragma once
#include "ItemAction.h"

//Item���������n�߂��ۂ̍s���̊��N���X
class ItemStartThrow : public ItemAction {
public:
	ItemStartThrow(Collision* collision, Item* item, Sound* sound);
	void Do()final;
};