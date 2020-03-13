#include "Item.h"
#include "Terrain.h"
#include <typeinfo.h>
#include "DxLib.h"

Item::Item(float x, float y, float height, float width, int object_number) :Object( x, y, height, width, object_number) {
	switch (this->object_number_) {
	case 0:
		graph_handle_ = LoadGraph("Image/Item.png");
		break;
	default:
		break;
	}
	quality_ = true;
	vector_ = 1;
	state_ = Item_Normal;
}
//Itemを持ち上げられている際に呼び出される関数
void Item::Carry() {
	x_ = carrier_->x_ + (carrier_->width_ - width_) / 2;//xを
	y_ = carrier_->y_ - height_;
	vector_ = carrier_->vector_;
}
//Itemを投げ始める際に呼び出される関数
void Item::Throw() {
	state_ = Item_Throw;
	if (vector_ == 1) {
		x_ = carrier_->Right();
	}
	else {
		x_ = carrier_->Left() - width_;
	}
		y_ = carrier_->Top();
}
void Item::Push(float num, Object *object) {
	if (object->CanMoveX(num / 4)) {
		object->MoveX(num / 4);
		MoveX(num / 4);
	}
}
void Item::Hit(int check, Object * object) {
	if (typeid(*object) == typeid(Terrain) || typeid(*object) == typeid(Item)) {
		switch (check) {
		case 1:
			x_ = object->Left() - width_ ;
			break;
		case 2:
			x_ = object->Right();
			break;
		case 3:
			y_ = object->Top() - height_;
			break;
		case 4:
			y_ = object->Base();
		default:
			break;
		}
	}
}

int Item::MapCheck(float num) {
	int check = 0;
	if (Right() + num > map_right_->Right()) check = 1;
	else if (Left() + num < map_left_->Left()) check = 2;
	return check;
}
void Item::Initialize(IStateChanger *stateChanger,std::vector<Object*>& stage){
	Object::Initialize(stateChanger, stage);
	map_left_, map_right_ = nullptr;
	for (auto i : (*stage_)) {
		if (typeid(*i) == typeid(Terrain)) {
			if (map_left_ == nullptr) map_left_ = i;
			else if (map_left_->Left() > i->Left()) map_left_ = i;
			if (map_right_ == nullptr) map_right_ = i;
			else if (map_right_->Right() < i->Right()) map_right_ = i;
		}
	}
}
void Item::Update() {
	const float kGravity = 4.0f;
	const float kThrowSpeed = 10.0f;
	switch (state_) {
	case Item_Normal:
		MoveY(kGravity);
		break;
	case Item_Picked:
		Carry();
		break;
	case Item_Throw:
		MoveX(kThrowSpeed * vector_);
		break;
	}
}
void Item::Draw() {
	if (vector_ == 1) DrawModiGraphF(x_, y_, x_ + width_, y_, x_ + width_, y_ + height_, x_, y_ + height_, graph_handle_, TRUE);
	else DrawModiGraphF(x_ + width_, y_, x_, y_, x_, y_ + height_, x_ + width_, y_ + height_, graph_handle_, TRUE);
}
int Item::CheckX(float num, const Object *object) {
	int check = 0;
	if (object->quality_ &&
		((state_ != Item_Picked && object != this) ||
		(state_ == Item_Picked && object != this && object != carrier_))) {
		if (Object::Check(x_ + num, y_, object)) {
			if (num > 0) check = 1;//地形の左側から衝突した
			else check = 2;//地形の右側から衝突した
		}
	}
	return check;
}
int Item::CheckY(float num, const Object *object) {
	int check = 0;
	if (object->quality_ &&
		((state_ != Item_Picked && object != this) ||
		(state_ == Item_Picked && object != this && object != carrier_))) {
		if (Object::Check(x_, y_ + num, object)) {
			if (num > 0) check = 3;//地形の上側から衝突した
			else check = 4;//地形の下から衝突した
		}
	}
	return check;
}
bool Item::CanMoveX(float num) {
	bool can_move = true;
	if (MapCheck(num) == 0) {
		for (auto i : (*stage_)) {
			if (CheckX(num, i) != 0 && !i->CanMoveX(num)) {
				can_move = false;
				break;
			}
		}
	}
	return can_move;
}
bool Item::CanMoveY(float num) {
	bool can_move = true;
	for (auto i : (*stage_)) {
		if (CheckY(num, i) != 0 && !i->CanMoveY(num)) {
			can_move = false;
			break;
		}
	}
	return can_move;
}
void Item::MoveX(float num) {
	bool hit = false;
	for (auto i : (*stage_)) {
		if (CheckX(num, i) != 0) {
			//	Push(num, i);
			Hit(CheckX(num, i), i);
			hit = true;
			state_ = Item_Normal;
			break;
		}
	}
	//ここからマップ外に移動してしまう際の処理
	if (MapCheck(num) != 0) {
		hit = true;
		MapHit(MapCheck(num));
	}
	if (!hit) {
		x_ += num;
	}
}
void Item::MoveY(float num) {
	bool hit = false;
	for (auto i : (*stage_)) {
		if (CheckY(num, i) != 0) {
			Hit(CheckY(num, i), i);
			hit = true;
			break;
		}
	}
	//ここからマップ外に移動してしまう際の処理
	if (!hit) {
		y_ += num;
	}
}
void Item::MapHit(int mapcheck) {
		state_ = Item_Normal;
		switch (mapcheck) {
		case 1:
			x_ = map_right_->Right() - width_;
			break;
		case 2:
			x_ = map_left_->Left();
			break;
		default:
			break;
		}

}
bool Item::CanPicked(const Object *object) {
	bool can_picked = true;
	if (state_ == Item_Normal) {
		float distance_X = (object->Left() + object->Right() - width_) / 2;
		float distance_Y = object->Top() - height_;
		for (auto i : (*stage_)) {
			if (Object::Check(distance_X , distance_Y, i)) {
				can_picked = false;
				break;
			}
		}
	}
	else can_picked = false;
 	return can_picked;
}
void Item::Picked( Object *object) {
	state_ = Item_Picked;
	carrier_ = object;
}
bool Item::CanPutted() {
	bool canputted = true;
	if (state_ != Item_Picked) {
		canputted = false;
	}else{
		for (auto i : (*stage_)) {
			if ((carrier_->vector_ == 1 && Object::Check(carrier_->Right(), carrier_->Base() - height_, i) ||
				carrier_->vector_ == -1 && Object::Check(carrier_->Left() - width_,carrier_->Base() - height_,i))) {
				canputted = false; 
				break;
			}
		}
	}
	return canputted;
}
void Item::Putted() {
	if (carrier_->vector_ == 1) {
		Object::Set(carrier_->Right(),carrier_->Base() - height_);
	}
	else {
		Object::Set(carrier_->Left() - width_, carrier_->Base() - height_);
	}
	state_ = Item_Normal;
}
bool Item::CanThrew() {
	bool can_putted = true;
	if (state_ != Item_Picked) {
		can_putted = false;
	}
	else {
		for (auto i : (*stage_)) {
			if ((carrier_->vector_ == 1 && Object::Check(carrier_->Right(), carrier_->Base() - height_, i) ||
				carrier_->vector_ == -1 && Object::Check(carrier_->Left() - width_, carrier_->Base() - height_, i))) {
				can_putted = false;
				break;
			}
		}
	}
	return can_putted;
}
void Item::Threw() {
	if (carrier_->vector_ == 1) Object::Set(carrier_->Right(), carrier_->Base() - height_);
	else Object::Set(carrier_->Left()- width_, carrier_->Base() - height_);
	state_ = Item_Throw;
}
void Item::Retry() {
	Object::Retry();
	state_ = Item_Normal;
	vector_ = 1;
}