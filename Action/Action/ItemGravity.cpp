#include "ItemGravity.h"
#include <tuple>

ItemGravity::ItemGravity(Collision *collision, Item *item, Sound* sound) : ItemAction(collision, item,sound) {
}
void ItemGravity::MoveY(float num) {
	//プレイヤーのX軸の移動を行う
	bool hit = false;
	int hitpoint;
	std::vector<Object*> hitobject;
	std::tie(hitpoint, hitobject) = collision_->HitCheckY(num, item_);
	if (hitpoint != 0 && !hitobject.empty()) {
		itemhit_->HitProcess(hitpoint, *hitobject.begin());
		hit = true;
	}
	if (!hit) {
		item_->y_ += num;
	}
}

void ItemGravity::Do() {
	MoveY(kGravity);
}