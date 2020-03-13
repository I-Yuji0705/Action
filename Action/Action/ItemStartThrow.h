#pragma once
#include "ItemAction.h"

//Itemが投げられ始めた際の行動の基底クラス
class ItemStartThrow : public ItemAction {
public:
	ItemStartThrow(Collision* collision, Item* item, Sound* sound);
	void Do()final;
};