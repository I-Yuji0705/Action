#include "Player.h"
#include <math.h>
#include <typeinfo.h>
#include <cstdlib>
#include "DxLib.h"
#include "Terrain.h"
#include "Item.h"
void Player::Action() {
	if (Keyboard::getInstance()->CheckKey(KEY_INPUT_RIGHT) != 0) { //右キーが押されていたら
		vector = 1;
		Move(&x, 10.0f);
	}
	if (Keyboard::getInstance()->CheckKey(KEY_INPUT_LEFT) != 0) { //左キーが押されていたら
		vector = -1;
		Move(&x, -10.0f);
	}
	if ((Keyboard::getInstance()->CheckKey(KEY_INPUT_UP) == 1 && playerState == State_Land) ||
		(Keyboard::getInstance()->CheckKey(KEY_INPUT_UP) > 1 && angle != 0)) {
		Move(&y, -10 * (float)cos(angle * 3.141592f * 1 / 120));
		angle++;
		if (angle > 60) angle = 60;
	}
	else if (angle != 0) {
		angle = 0;
	}
	if (Keyboard::getInstance()->CheckKey(KEY_INPUT_SPACE) == 1) { 
		if (isCarrier) Throw();
			else Pick(); 
	}
	if (Keyboard::getInstance()->CheckKey(KEY_INPUT_DOWN) == 1 && isCarrier)
		Put();
}
void Player::Push(float num, Object *object) {
	if (object->CanMove(&object->x, num / 4)) {
		object->Move(&object->x, num / 4);
		Move(&x, num / 4);
		if (isCarrier)carryon->Move(&object->x, num / 4);
	}
}
void Player::Pick() {
	Object *goods = stage[0];
	for (int i = 0; i < stage[i]->object_num; i++) {
		if (Check(stage[i]) &&
			(goods->x == -1 ||
			abs(this->x - stage[i]->x) < abs(this->x - goods->x) ||
			(abs(this->x - stage[i]->x) == abs(this->x - goods->x) &&
				stage[i]->Base() < goods->Base()))) {
			goods = stage[i];
		}
	}
	if (goods->CanPicked(this)) {
		goods->Picked(this);
		isCarrier = true;
		carryon = goods;
	}
}
void Player::Put() {
	if (carryon->CanPutted()) {
		carryon->Putted();
		isCarrier = false;
	}
}
void Player::Throw() {
	if (carryon->CanThrew()) {
		carryon->Threw();
		isCarrier = false;
	}
}
bool Player::Check(Object *object) {
	bool check = false;
	if (object->quality &&object !=this && Base() > object->Top() && Top() < object->Base()) {
		if (vector == 1 &&
			Right() <= object->Left() && Right() + width >= object->Left()) {
			check = true;
		}
		else if(vector == -1 &&
			Left() >= object->Right() && Left() - width <= object->Right()){
			check = true;
		}
	}
	return check;
}
void Player::Hit(int check, Object * object) {
	if (typeid(*object) == typeid(Terrain) || typeid(*object) == typeid(Item)) {
		switch (check) {
		case 1:
			x = object->Left() - width;
			break;
		case 2:
			x = object->Right() ;
			break;
		case 3:
			y = object->Top() - height;
			playerState = State_Land;
			break;
		case 4:
			y = object->Base() ;
		default:
			break;
		}
	}
}
int Player::MapCheck(float *point, float num) {
	int check = 0;
	if (point == &x) {
		if (Right() + num > mapRight->Right()) check = 1;
		if (Left() + num < mapLeft->Left()) check = 2;
	}
	return check;
}
void Player::RetryCheck() {//穴に落ちたかの確認
	if(y > 480.0f) playerState = State_Retry;
}
void Player::Dance() {
	switch (danceNum) {
	case 0:
		vector = -1;
		x += 2;
		danceTimer++;
		if (danceTimer > 60) {
			danceNum++;
			danceTimer = 0;
		}
		break;
	case 1:
		vector = 1;
		x -= 2;
		danceTimer++;
		if (danceTimer > 90) {
			danceNum++;
			danceTimer = 0;
		}
		break;
	case 2:
		vector = -1;
		x += 2;
		danceTimer++;
		if (danceTimer > 30) {
			danceNum++;
			danceTimer = 0;
		}
		break;
	case 3:
		vector = -1;
		y -= 2;
		danceTimer++;
		if (danceTimer > 15) {
			danceNum++;
			danceTimer = 0;
		}
		break;
	case 4:
		vector = -1;
		y += 2;
		danceTimer++;
		if (danceTimer > 15) {
			danceNum++;
			danceTimer = 0;
		}
		break;
	case 5:
		vector = 1;
		y -= 2;
		danceTimer++;
		if (danceTimer > 45) {
			danceNum++;
			danceTimer = 0;
		}
		break;
	default:
		stateChanger->ChangeState(Game_Clear);
		break;
	}
}
void Player::Set(float x, float y, float height, float width, int objNum) {
	Object::Set(x, y, height, width, objNum);
	switch (this->objNum) {
	case 0:
		graphHandle =LoadGraph("Image/Player.png");
		break;
	default:
		break;
	}
	quality = true;
	vector = 1;
	angle = 0;
	danceTimer = 0;
	danceNum = 0;
	isCarrier = false;
	playerState = State_Air;
}
void Player::Initialize(IStateChanger *stateChanger, Object *stage[]) {
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
void Player::Update() {
	switch (playerState) {
	case State_Clear:
		Dance();
		break;
	case State_Retry:
		stateChanger->ChangeState(Game_Retry);
		break;
	default:
		Action();	
		Move(&y, 5.0f);
		RetryCheck();
		break;
	}
}
void Player::Draw() {
	if(vector ==1) DrawModiGraphF(x, y, x + width, y, x + width, y + height, x, y + height, graphHandle, TRUE);
	else DrawModiGraphF(x + width, y, x, y, x, y + height, x + width, y + height, graphHandle, TRUE);
}
int Player::Check(float *point, float num, Object *object) {
	int check = 0;
	if (object->quality &&
		((!isCarrier && object != this) ||
		(isCarrier && object != carryon && object != this))) {
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
bool Player::CanMove(float *point, float num) {
	bool canMove = true;
	for (int i = 0; i < object_num; i++) {
		if (Object::Check(point, num, stage[i]) != 0 && stage[i]->CanMove(&stage[i]->x,num/4)) {
			canMove = false;
			break;
		}
	}
	return canMove;
}
void Player::Move(float *point, float num) {
	bool hit = false;
	if (isCarrier) {
		for (int i = 0; i < stage[i]->object_num; i++) {
			if ((carryon->Check(&carryon->x, num, stage[i]) != 0 && point == &x)||
				(carryon->Check(&carryon->y, num, stage[i]) != 0 && point == &y)) {
				if (point == &x) {
					Push(num, stage[i]);
				}
				Hit(Check(point, num, stage[i]), stage[i]);
				hit = true;
				break;
			}
		}
	}
	if (!hit) {
		for (int i = 0; i < stage[i]->object_num; i++) {
			if (Check(point, num, stage[i]) != 0) {
				if (point == &x && playerState == State_Land) {
					//アイテムに接触している時
					Push(num, stage[i]);
				}
				Hit(Check(point, num, stage[i]), stage[i]);
				hit = true;
				break;
			}
		}
	}
	//ここからマップ外に移動してしまう際の処理
	if (MapCheck(point, num) != 0) {
		hit = true;
		//state = State_Normal;
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
		if (point == &x) x += num;
		else {
			y += num;
			playerState = State_Air;
		}
	}
}
bool Player::CanPicked(Object * object) {
	bool canpicked = true;
	for (int i = 0; i < stage[i]->object_num; i++) {
		if (Object::Check(object->x - width, object->y - height, object) != 0) {
			canpicked = false;
			break;
		}
	}
	return canpicked;
}
void Player::Picked(Object *object) {
}
void Player::Clear() {
	playerState = State_Clear;
	stateChanger->ChangeState(Game_Dance);
}
void Player::Retry() {
	Object::Retry();
	playerState = State_Air;
	isCarrier = false;
	vector = 1;
}