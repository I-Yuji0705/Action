#include "ItemGravity.h"
#include <tuple>

ItemGravity::ItemGravity(Sound* sound, Collision *collision, Item *item,ItemHit* itemhit) : ItemAction(item) {
	sound_ = sound;
	collision_ = collision;
	itemhit_ = itemhit;
}
void ItemGravity::MoveY(float num) {
	//プレイヤーのX軸の移動を行う
	bool hit = false;
	int hitpoint;
	float distance;
	std::vector<Object*> hitobject;
	std::tie(hitpoint, distance, hitobject) = collision_->HitCheckY(num, item_);
	if (hitpoint != 0  &&!hitobject.empty()) {
		itemhit_->HitObjects(hitpoint, distance);
		hit = true;
	}
	if (!hit) {
		item_->y_ += num;
	}
}

void ItemGravity::Do() {
	MoveY(gravity_.kGravity);
}