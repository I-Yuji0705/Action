#include "Object.h"
#include "DxLib.h"

int Object::object_num = 0;
void Object::Finalize() {
	DeleteGraph(graphHandle);
}
float Object::Left() {
	return x;
}
float Object::Right() {
	return x + width;
}
float Object::Top() {
	return y;
}
float Object::Base() {
	return y + height;
}
bool Object::Check(float x, float y, Object *object) {
	bool check = false;
	if (object->quality &&
		y + height > object->Top() && y < object->Base() &&
		x + width > object->Left() && x < object->Right())
		check = true;
	return check;
}
void Object::RelaySet(float x,float y) {
	this->retryX = x;
	this->retryY = y;
}
void Object::Set(float x, float y) {
	this->x = x;
	this->y = y;
}
void Object::Set(float x, float y, float height, float width) {
	Set(x, y);
	this->width = width;
	this->height = height;
}
void Object::Set(float x,float y, float height, float width, int objNum) {
	Set(x, y, height, width);
	this->retryX = x;
	this->retryY = y;
	this->objNum = objNum;
	object_num++;
}
void Object::Initialize(IStateChanger *stateChanger, Object *stage[]) {
	this->stateChanger = stateChanger;
	this->stage = stage;
}
void Object::Draw() {
	DrawModiGraphF(x, y, x + width, y,x + width, y + height, x, y + height,graphHandle, TRUE);//Float型の四点の座標から画像を描写
}
int Object::Check(float *point, float num, Object *object) {
	int check = 0;
	if (object != this) {
		if (object->quality) {
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
	}
	return check;
}
bool Object::CanMove(float *point,float num) {
	return false;
}
bool Object::CanPicked(Object *object) {
	return false;
}
bool Object::CanPutted() {
	return false;
}
bool Object::CanThrew() {
	return false;
}
void Object::Retry() {
	Set(retryX, retryY);
}