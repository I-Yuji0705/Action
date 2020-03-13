#include "ItemThrew.h"
#include <tuple>

ItemThrew::ItemThrew(Collision *collision, Item *item, Sound* sound) : ItemAction(collision, item, sound) {
}

void ItemThrew::MoveX(float num) {
	//プレイヤーのX軸の移動を行う
	bool hit = false;
	int hitpoint;
	std::vector<Object*> hitobject;
	std::tie(hitpoint, hitobject) = collision_->HitCheckX(num, item_);
	if (hitpoint != 0 && !hitobject.empty()) {
		itemhit_->HitProcess(hitpoint, *hitobject.begin());
		hit = true;
		sound_->PlaySe(Se_Hit, item_);
	}
	int mapcheck = collision_->MapCheck(item_->Left() + num, item_);
	if (mapcheck != 0) {
		sound_->PlaySe(Se_Hit, item_);
		itemhit_->MapHit(mapcheck);
		hit = true;
	}
	if (!hit) {
		item_->x_ += num;
	}
}

void ItemThrew::Do() {
	MoveX(kThrowSpeed * item_->vector_);
}