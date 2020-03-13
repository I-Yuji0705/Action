#include "Object.h"
#include "DxLib.h"

int Object::object_num = 0;
void Object::Finalize() {
	DeleteGraph(graphHandle);
}
void Object::Draw() {
	DrawModiGraphF(x, y, x + width, y,x + width, y + height, x, y + height,graphHandle, TRUE);
}
void Object::Set(float x,float y, float height, float width, int objNum) {
	Set(x, y, height, width);
	this->retryX = x;
	this->retryY = y;
	this->objNum = objNum;
	object_num++;
}
void Object::Set(float x, float y, float height, float width) {
	Set(x, y);
	this->width = width;
	this->height = height;
}
void Object::Set(float x, float y) {
	this->x = x;
	this->y = y;
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

int Object::Check(float *point, float num, Object *object) {
	int check = 0;
	if (object != this) {
		if (object->quality) {
			if (&x == point) {
				if (Base() > object->Top() && Top() < object->Base()) {
					if (Right() + num > object->Left() && Right() + num < object->Right()) {
						//�n�`�̍�������Փ˂�����
						check = 1;
					}
					else if (Left() + num < object->Right() && Left() + num >object->Left()) {
						//�n�`�̉E������Փ˂�����
						check = 2;
					}
				}
			}
			else {
				if (Right() > object->Left() && Left() < object->Right()) {
					if (Base() + num > object->Top() && Base() + num < object->Base()) {
						//�n�`�̏㑤����Փ˂�����
						check = 3;
					}
					if (Top() + num < object->Base() && Top() + num > object->Top()) {
						//�n�`�̉�����Փ˂�����
						check = 4;
					}
				}
			}
		}
	}
	return check;
}
int Object::Check(float x, float y, Object *object) {
	int check = 0;
	if (object != this) {
		if (object->quality) {
			if (y + height > object->Top() && y < object->Base()) {
				if (x + width > object->Left() && x + width < object->Right()) {
					//�n�`�̍�������Փ˂�����
					check = 1;
				}
				else if (x  < object->Right() && x  >object->Left()) {
					//�n�`�̉E������Փ˂�����
					check = 2;
				}
			}
			if (x + width > object->Left() && x < object->Right()) {
				if (y + height > object->Top() && y + height < object->Base()) {
					//�n�`�̏㑤����Փ˂�����
					check = 3;
				}
				if (y  < object->Base() && y  > object->Top()) {
					//�n�`�̉�����Փ˂�����
					check = 4;
				}
			}
		}
	}
	return check;
}
void Object::Picked(Object *object) {
}
void Object::Putted() {
}
bool Object::CanPutted() {
	return false;
}
bool Object::CanPicked(Object *object) {
	return false;
}
void Object::Move(float *point, float num) {
}
bool Object::CanThrew() {
	return false;
}
void Object::Threw() {
}
void Object::Initialize(Object **stage) {
	this->stage = stage;
}
void Object::Initialize(IStateChanger *stateChanger, Object **stage) {
	this->stateChanger = stateChanger;
	this->stage = stage;
}
void Object::Retry() {
	Set(retryX, retryY);
}
void Object::RelaySet(float x,float y) {
	this->retryX = x;
	this->retryY = y;
}