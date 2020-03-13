#include "ItemAction.h"

ItemAction::ItemAction(Collision *collision, Item *item, Sound* sound) : ActionBase(collision,sound){
	item_ = item;
	itemhit_ = new ItemHit(collision, item_);
}