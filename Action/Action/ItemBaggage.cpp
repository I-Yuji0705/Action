#include "ItemBaggage.h"

///<summary>
///<para>コンストラクタ</para>
///</summary>
ItemBaggage::ItemBaggage(Item *item) : ItemAction(item) {
}

///<summary>
///<para>行動処理</para>
///<para>carrier_の頭上に来るように位置を変更し、向きが同じになる様に更新する</para>
///</summary>
void ItemBaggage::Do() {
	item_->Set(item_->carrier_->Center_X() - item_->GetWidth() / 2, item_->carrier_->Top() - item_->GetHeight());
	item_->vector_ = item_->carrier_->vector_;
}