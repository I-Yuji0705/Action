#include "Item.h"
#include "Terrain.h"
#include <typeinfo.h>
#include "DxLib.h"
#define Gravity 5f

void Item::Initialize(Object **stage) {
	Object::Initialize(stage);
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
void Item::Initialize(IStateChanger *stateChanger, Object **stage) {
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
		graphHandle = LoadGraph("Image/Enemy.png");
		break;
	default:
		break;
	}
	quality = true;
	vector = 1;
	state = State_Normal;
}
void Item::Update(Terrain *terrain) {
	switch (state) {
	case State_Normal:
		Move(&y, 5, terrain);
		break;
	case State_Picked:
		Carry();
		break;
	case State_Throw:
		Move(&x,10.0f * vector,terrain);
		break;
	}
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
void Item::Picked(Object *object) {
	state = State_Picked;
	carrier = object;
}
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
int Item::Check(float *point, float num, Object *object) {
	DrawString(200, 200, "Check OK" ,GetColor(255, 255, 255));
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
int Item::Check(float x, float y, Object *object) {
	int check = 0;
	if (object != this) {
		if (object->quality) {
				if (y + height > object->Top() && y < object->Base()) {
					if (x + width  > object->Left() && x + width  < object->Right()) {
						//地形の左側から衝突した時
						check = 1;
					}
					else if (x  < object->Right() && x  >object->Left()) {
						//地形の右側から衝突した時
						check = 2;
					}
				}
				if (x + width > object->Left() && x < object->Right()) {
					if (y + height  > object->Top() && y + height  < object->Base()) {
						//地形の上側から衝突した時
						check = 3;
					}
					if (y  < object->Base() && y  > object->Top()) {
						//地形の下から衝突した時
						check = 4;
					}
				}
		}
	}
	return check;
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
bool Item::Move(float *point, float num, Terrain *terrain) {
	bool hit = false;
	for (int i = 0; i < terrain->terrain_num; i++) {
		if (Check(point, num, terrain + i) != 0) {
			Hit(Check(point, num, terrain + i), terrain + i);
			hit = true;
			state = State_Normal;
			break;
		}
	}
	if (!hit) {
		if (&x == point) x += num;
		else {
			y += num;
		}
	}
	return hit;
}
void Item::Move(float *point, float num) {
	bool hit = false;
	for (int i = 0; i < stage[i]->object_num; i++) {
		if (Check(point, num, stage[i]) != 0) {
			if (typeid(*stage[i]) == typeid(Item) && point == &x) {
				stage[i]->Move(&stage[i]->x, num / 2);
				Move(&x, num / 2);
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
int Item::MapCheck(float *point,float num) {
	int check = 0;
	if (point == &x) {
		if (Right() + num > mapRight->Right()) check = 1;
		if (Left() + num < mapLeft->Left()) check = 2;
	}
	return check;
}
void Item::Draw() {
	if (vector == 1) DrawModiGraphF(x, y, x + width, y, x + width, y + height, x, y + height, graphHandle, TRUE);
	else DrawModiGraphF(x + width, y, x, y, x, y + height, x + width, y + height, graphHandle, TRUE);
}
bool Item::CanPicked(Object *object) {
	bool canpicked = true;
	if (state == State_Normal) {
		for (int i = 0; i < stage[i]->object_num; i++) {
			if (Check(object->x , object->y - height, stage[i]) != 0) {
				canpicked = false;
				break;
			}
		}
	}
	else canpicked = false;
	return canpicked;
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
bool Item::CanPutted() {
	bool canputted = true;
	if (state != State_Picked) {
		canputted = false;
	}else{
		for (int i = 0; i < stage[i]->object_num; i++) {
			if ((carrier->vector == 1 && Check(carrier->Right(), carrier->Base() - height, stage[i]) ||
				carrier->vector == -1 && Check(carrier->Left() - width,carrier->Base() - height,stage[i])) != 0) {
				canputted = false; 
				break;
			}
		}
	}
	return canputted;
}
bool Item::CanThrew() {
	bool canputted = true;
	if (state != State_Picked) {
		canputted = false;
	}
	else {
		for (int i = 0; i < stage[i]->object_num; i++) {
			if ((carrier->vector == 1 && Check(carrier->Right(), carrier->Base() - height, stage[i]) ||
				carrier->vector == -1 && Check(carrier->Left() - width, carrier->Base() - height, stage[i])) != 0) {
				canputted = false;
				break;
			}
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