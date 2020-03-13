#include "ItemThrew.h"
#include <tuple>

ItemThrew::ItemThrew(Sound* sound, Collision *collision, Item *item,ItemHit* itemhit) : ItemAction(item) {
	sound_ = sound;
	collision_ = collision;
	itemhit_ = itemhit;
}

void ItemThrew::MoveX(float num) {
	//プレイヤーのX軸の移動を行う
	bool hit = false;
	int hitpoint;
	float distance;
	std::vector<Object*> hitobjects;
	std::tie(hitpoint, distance, hitobjects) = collision_->HitCheckX(num, item_);//移動した際に当たるオブジェクトと当たる場所の算出
	if (hitpoint != 0 && !hitobjects.empty()) {//当たったObjectがあったか
		itemhit_->HitObjects(hitpoint, distance);//Hitした時のプレイヤーの位置を調整する
		if(distance != 0.0f)
			sound_->PlaySe(Se_Hit, item_);
		hit = true;
	}
	std::tie(hitpoint, distance) = collision_->MapCheck(item_->Left() + num, item_);
	if (hitpoint != 0) {//マップ外に移動してしまうか確認する処理
  		itemhit_->HitObjects(hitpoint, distance);
		hit = true;
		sound_->PlaySe(Se_Hit, item_);
	}
	if (!hit) {
		item_->x_ += num;
	}
}

void ItemThrew::Do() {
	const float kThrowSpeed = 10.0f;
	MoveX(kThrowSpeed * item_->vector_);
}