#include "Item.h"
#include "Terrain.h"
#include <typeinfo.h>
#include "DxLib.h"

void Item::Carry() {
	x = carrier->x + (carrier->width - width) / 2;
	y = carrier->y - height;
	vector = carrier->vector;
}
void Item::Throw() {
	state = State_Throw;
	if (vector == 1) {
		x = carrier->Right();
	}
	else {
		x = carrier->Left() - width;
	}
		y = carrier->Top();
}
void Item::Push(float num, Object *object) {
	if (object->CanMove(&object->x, num / 4)) {
		object->Move(&object->x, num / 4);
		Move(&x, num / 4);
	}
}
void Item::Hit(int check, Object * object) {
	if (typeid(*object) == typeid(Terrain) || typeid(*object) == typeid(Item)) {
		switch (check) {
		case 1:
			x = object->Left() - width ;
			break;
		case 2:
			x = object->Right();
			break;
		case 3:
			y = object->Top() - height;
			break;
		case 4:
			y = object->Base();
		default:
			break;
		}
	}
}
int Item::MapCheck(float *point,float num) {
	int check = 0;
	if (point == &x) {
		if (Right() + num > mapRight->Right()) check = 1;
		if (Left() + num < mapLeft->Left()) check = 2;
	}
	return check;
}
void Item::Initialize(IStateChanger *stateChanger, Object *stage[]) {
	Object::Initialize(stateChanger, stage);
	mapLeft, mapRight = nullptr;
	for (int i = 0; i < object_num; i++) {
		if (typeid(*stage[i]) == typeid(Terrain)) {
			if (mapLeft == nullptr) mapLeft = stage[i];
			if (mapRight == nullptr) mapRight = stage[i];

			if (mapLeft->Left() > stage[i]->Left()) mapLeft = stage[i];
			if (mapRight->Right() < stage[i]->Right()) mapRight = stage[i];
		}
	}
}
void Item::Set(float x, float y, float height, float width, int objNum) {
	Object::Set(x, y, height, width, objNum);
	switch (this->objNum) {
	case 0:
		graphHandle = LoadGraph("Image/Item.png");
		break;
	default:
		break;
	}
	quality = true;
	vector = 1;
	state = State_Normal;
}
void Item::Update() {
	switch (state) {
	case State_Normal:
		Move(&y, 5.0f);
		break;
	case State_Picked:
		Carry();
		break;
	case State_Throw:
		Move(&x, 10.0f * vector);
		break;
	}
}
void Item::Draw() {
	if (vector == 1) DrawModiGraphF(x, y, x + width, y, x + width, y + height, x, y + height, graphHandle, TRUE);
	else DrawModiGraphF(x + width, y, x, y, x, y + height, x + width, y + height, graphHandle, TRUE);
}
int Item::Check(float *point, float num, Object *object) {
	int check = 0;
	if (object->quality &&
		((state != State_Picked && object != this) ||
		(state == State_Picked && object != this && object != carrier ))) {
		if (&x == point) {
			if (Base() > object->Top() && Top() < object->Base()) {
				if (Right() + num > object->Left() && Right() + num < object->Right()) {
					//地形の左側から衝突した時
					check = 1;
				}
				else if (Left() + num < object->Right() && Left() + num >object->Left()) {
					//地形の右側から衝突した時
					check = 2;
				}
			}
		}
		else {
			if (Right() > object->Left() && Left() < object->Right()) {
				if (Base() + num > object->Top() && Base() + num < object->Base()) {
					//地形の上側から衝突した時
					check = 3;
				}
				if (Top() + num < object->Base() && Top() + num > object->Top()) {
					//地形の下から衝突した時
					check = 4;
				}
			}
		}
	}
	return check;
}
bool Item::CanMove(float *point, float num) {
	bool canMove = true;
	for (int i = 0; i < object_num; i++) {
		if (Check(point, num, stage[i])!= 0&& !stage[i]->CanMove(&stage[i]->x,num)) {
			canMove = false;
			break;
		}
	}
	return canMove;
}
void Item::Move(float *point, float num) {
	bool hit = false;
	for (int i = 0; i < stage[i]->object_num; i++) {
		if (Check(point, num, stage[i]) != 0) {
			if (point == &x) {
				Push(num, stage[i]);
			}
			Hit(Check(point, num, stage[i]), stage[i]);	
			hit = true;
			state = State_Normal;
			break;
		}
	}
	//ここからマップ外に移動してしまう際の処理
	if (MapCheck(point, num) != 0) {
		hit = true;
		state = State_Normal;
		switch (MapCheck(point, num)) {
		case 1:
			x = mapRight->Right() - width;
			break;
		case 2:
			x = mapLeft->Left();
			break;
		default:
			break;
		}
	}
	if (!hit) {
		if (&x == point) x += num;
		else y += num;
	}
}
bool Item::CanPicked(Object *object) {
	bool canpicked = true;
	if (state == State_Normal) {
		for (int i = 0; i < stage[i]->object_num; i++) {
			if (Object::Check(object->x , object->y - height, stage[i])) {
				canpicked = false;
				break;
			}
		}
	}
	else canpicked = false;
 	return canpicked;
}
void Item::Picked(Object *object) {
	state = State_Picked;
	carrier = object;
}
bool Item::CanPutted() {
	bool canputted = true;
	if (state != State_Picked) {
		canputted = false;
	}else{
		for (int i = 0; i < stage[i]->object_num; i++) {
			if ((carrier->vector == 1 && Object::Check(carrier->Right(), carrier->Base() - height, stage[i]) ||
				carrier->vector == -1 && Object::Check(carrier->Left() - width,carrier->Base() - height,stage[i]))) {
				canputted = false; 
				break;
			}
		}
	}
	return canputted;
}
void Item::Putted() {
	if (carrier->vector == 1) {
		Object::Set(carrier->Right(),carrier->Base() - height);
	}
	else {
		Object::Set(carrier->Left() - width, carrier->Base() - height);
	}
	state = State_Normal;
}
bool Item::CanThrew() {
	bool canputted = true;
	if (state != State_Picked) {
		canputted = false;
	}
	else {
		for (int i = 0; i < stage[i]->object_num; i++) {
			if ((carrier->vector == 1 && Object::Check(carrier->Right(), carrier->Base() - height, stage[i]) ||
				carrier->vector == -1 && Object::Check(carrier->Left() - width, carrier->Base() - height, stage[i]))) {
				canputted = false;
				break;
			}
		}
		if ((carrier->vector == 1 && carrier->Right() + width > mapRight->Right()) ||
			(carrier->vector == -1 && carrier->Left() - width < mapLeft->Left())) {
			canputted = false;
		}
	}
	return canputted;
}
void Item::Threw() {
	if (carrier->vector == 1) Object::Set(carrier->Right(), carrier->Top());
	else Object::Set(carrier->Left()- width, carrier->Top());
	state = State_Throw;
}
void Item::Retry() {
	Object::Retry();
	state = State_Normal;
	vector = 1;
}