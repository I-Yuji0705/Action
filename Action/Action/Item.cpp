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

Item::Item(float x, float y, float height, float width,Sound* sound) : Object( x, y, height, width,sound) {
	graph_handle_ = LoadGraph("Image/Item.png");
	quality_ = true;
	vector_ = 1;
	state_ = Item_Normal;
}

void Item::Initialize(IGameStateChanger *statechanger, Collision *collision) {
	Object::Initialize(statechanger, collision);
	this->collision_ = collision;
	itemaction_[Item_Baggage] = new ItemBaggage(collision_, this, sound_);
	itemaction_[Item_StartThrow] = new ItemStartThrow(collision_, this, sound_);
	itemaction_[Item_Threw] = new ItemThrew(collision_, this, sound_);
	itemaction_[Item_Putted] = new ItemPutted(collision_, this, sound_);
	itemaction_[Item_Gravity] = new ItemGravity(collision_, this, sound_);
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
		if (collision_->Check(posx, posy, this) || collision_->MapCheck(posx, this) != 0) {
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
		if (collision_->Check(posx, posy, this) || collision_->MapCheck(posx,this) != 0) {
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
	std::vector<Object*> hitobject;
	if (collision_->MapCheck(this->Left() + num, this) != 0) {
		canpushed = 0;
	}
	else {
		std::tie(hitpoint, hitobject) = collision_->HitCheckX(num, this);
		if (hitpoint != 0 && !hitobject.empty()) {
			for (auto i : hitobject) {
				if (i == *hitobject.begin() || canpushed > i->CanPushed(num)) {
					canpushed = i->CanPushed(num);
				}
			}
		}
	}
	return canpushed;
}
void Item::Pushed(float num) {
	int hitpoint;
	std::vector<Object*> hitobject;
	std::tie(hitpoint, hitobject) = collision_->HitCheckX(num, this);
	float canpushed = num;
	if (hitpoint != 0 && !hitobject.empty()) {
		for (auto i : hitobject) {
			i->Pushed(canpushed);
		}
	}
	x_ += canpushed;
}
