#pragma once
#include"ItemAction.h"

//Itemが置かれる際に行う行動の基底クラス
class ItemPutted : public ItemAction {
public:
	ItemPutted(Item *item);
	void Do() final;
};