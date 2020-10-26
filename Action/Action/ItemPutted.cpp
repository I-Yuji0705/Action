#include "ItemPutted.h"

///<summary>
///<para>コンストラクタ</para>
///</summary>
ItemPutted::ItemPutted(Item *item) : ItemAction(item) {
}

///<summary>
///<para>行動処理</para>
///<para>carrier_の向きから置く場所を決め、item_の位置を置く場所に変更する</para>
///<para>item_のstateを通常時に変え、carrier_をnullptrに変える</para>
///</summary>
void ItemPutted::Do() {
	float posx;
	float posy = item_->carrier_->Base() - item_->GetHeight();
	if (item_->carrier_->vector_ == 1) {
		posx = item_->carrier_->Right();
	}
	else {
		posx = item_->carrier_->Left() - item_->GetWidth();
	}
	item_->Set(posx, posy);
	item_->state_ = ItemState::Item_Normal;
	item_->carrier_ = nullptr;
}