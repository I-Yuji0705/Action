#include "ItemBaggage.h"

ItemBaggage::ItemBaggage(Collision *collision, Item *item, Sound* sound) : ItemAction(collision, item,sound) {
}

void ItemBaggage::Do() {
	item_->Set(item_->carrier_->Center_X() - item_->GetWidth() / 2, item_->carrier_->Top() - item_->GetHeight());
	item_->vector_ = item_->carrier_->vector_;
}