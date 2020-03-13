#include "Item.h"
#include "Terrain.h"
#include <typeinfo.h>
#include <assert.h>
#include <tuple>
#include "DxLib.h"
#include "ItemBaggage.h"
#include "ItemGravity.h"
#include "ItemPutted.h"
#include "ItemThrew.h"
#include "ItemStartThrow.h"

Item::Item(Sound* sound,Collision* collision,float x, float y, float height, float width) : Object(x, y, height, width) {
	sound_ = sound;
	collision_ = collision;
	graph_handle_ = LoadGraph("Image/Item.png");
	quality_ = true;
	vector_ = 1;
	state_ = Item_Normal; 
	itemhit_ = new ItemHit(collision_,this);
	itemaction_[Item_Baggage] = new ItemBaggage(this);
	itemaction_[Item_StartThrow] = new ItemStartThrow(this);
	itemaction_[Item_Threw] = new ItemThrew(sound_, collision_, this,itemhit_);
	itemaction_[Item_Putted] = new ItemPutted(this);
	itemaction_[Item_Gravity] = new ItemGravity(sound_, collision_, this,itemhit_);
}

void Item::Initialize() {
	carrier_ = nullptr;
}
//Item‚ÌXVˆ—
void Item::Update() {
	switch (state_) {
	case Item_Normal:
		itemaction_[Item_Gravity]->Do();
		break;
	case Item_Picked:
		itemaction_[Item_Baggage]->Do();
		break;
	case Item_Throw:
		itemaction_[Item_Threw]->Do();
		break;
	default:
		assert(false);
		break;
	}
}
//Item‚Ì•`ŽÊˆ—
void Item::Draw() {
	if (vector_ == 1) DrawModiGraphF(x_, y_, x_ + width_, y_, x_ + width_, y_ + height_, x_, y_ + height_, graph_handle_, TRUE);
	else DrawModiGraphF(x_ + width_, y_, x_, y_, x_, y_ + height_, x_ + width_, y_ + height_, graph_handle_, TRUE);
}


bool Item::CanPicked(const Object *object) {
	bool canpicked = true;
	if (collision_->Check(object->Center_X() - GetWidth() / 2, object->Top() - GetHeight(), this)) {
		canpicked = false;
	}
	return canpicked;
}
void Item::Picked(Object *object) {
	state_ = Item_Picked;
	carrier_ = object;
	itemaction_[Item_Baggage]->Do();
}
bool Item::CanPutted() {
	bool canputted = true;
	if (state_ != Item_Picked) {
		canputted = false;
	}
	else {
		float posx;
		float posy = carrier_->Base() - GetHeight();
		if (vector_ == 1) {
			posx = carrier_->Right();
		}
		else {
			posx = carrier_->Left() - GetWidth();
		}
		int mapcheck;
		float distance;
		std::tie(mapcheck, distance) = collision_->MapCheck(posx, this);
		if (collision_->Check(posx, posy, this) || mapcheck != 0) {
			canputted = false;
		}
	}
	return canputted;
}
void Item::Putted() {
	itemaction_[Item_Putted]->Do();
}
bool Item::CanThrew() {
	bool canthrew = true;
	if (state_ != Item_Picked) {
		canthrew = false;
	}
	else {
		float posx;
		float posy = carrier_->Base() - GetHeight();
		if (vector_ == 1) {
			posx = carrier_->Right();
		}
		else {
			posx = carrier_->Left() - GetWidth();
		}
		int mapcheck;
		float distance;
		std::tie(mapcheck, distance) = collision_->MapCheck(posx, this);
		if (collision_->Check(posx, posy, this) || mapcheck != 0) {
			canthrew = false;
		}
	}
	return canthrew;
}
void Item::Threw() {
	itemaction_[Item_StartThrow]->Do();
}
void Item::Retry() {
	Object::Retry();
	state_ = Item_Normal;
	vector_ = 1;
}
float Item::CanPushed(float num) {
	float canpushed = num / 2;
	int hitpoint;
	float distance;
	std::vector<Object*> hitobject;
	std::tie(hitpoint, distance) = collision_->MapCheck(Left() + num / 2, this);
	if (hitpoint != 0) {
		canpushed = distance;
	}
	else {
		std::tie(hitpoint, distance, hitobject) = collision_->HitCheckX(num / 2, this);
		if (hitpoint != 0 ){
			if (distance != 0.0f) {
				canpushed = distance;
			}else if(!hitobject.empty()) {
				for (auto i : hitobject) {
					if (std::abs(canpushed) > std::abs(i->CanPushed(num / 2))) {
						canpushed = i->CanPushed(num / 2);
					}
				}
			}
		}
	}
	return canpushed;
}
void Item::Pushed(float num) {
	int hitpoint;
	float distance;
	std::vector<Object*> hitobject;
	std::tie(hitpoint, distance, hitobject) = collision_->HitCheckX(num, this);
	if (hitpoint != 0 && !hitobject.empty()) {
		for (auto i : hitobject) {
			i->Pushed(num);
		}
	}
	Set(Left() + num, Top());
}
