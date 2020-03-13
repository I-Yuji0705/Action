#include "ItemStartThrow.h"

ItemStartThrow::ItemStartThrow(Collision *collision, Item *item, Sound* sound) : ItemAction(collision, item, sound) {
}

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
}