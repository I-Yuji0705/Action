#include "ItemStartThrow.h"

///<summary>
///<para>コンストラクタ</para>
///</summary>
ItemStartThrow::ItemStartThrow(Item *item) : ItemAction(item) {
}

///<summary>
///<para>行動処理</para>
///<para>carrier_の向きから投げられ始める場所を決め、item_の位置を投げられ始める場所に変更する</para>
///<para>tem_のstateを変え、carrier_をnullptrに変える</para>
///</summary>
void ItemStartThrow::Do() {
	float posx;
	float posy = item_->carrier_->Base() - item_->GetHeight();
	if (item_->vector_ == 1) {
		posx = item_->carrier_->Right();
	}
	else {
		posx = item_->carrier_->Left() - item_->GetWidth();
	}
	item_->Set(posx, posy);
	item_->state_ = Item_Throw;
	item_->carrier_ = nullptr;
}