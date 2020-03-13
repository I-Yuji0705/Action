#include "Camera.h"
#include <typeinfo.h>
#include "DxLib.h"
#include "Player.h"
#define CameraRight 640//描写できる右端の最大値
#define CameraBase 480//描写できる下端の最大値
void Camera::Initialize(Object *stage[]) {
	mapLeft, mapRight = nullptr;
	for (int i = 0; i < stage[i]->object_num; i++) {
		if (typeid(*stage[i]) == typeid(Terrain)) {
			if (mapLeft == nullptr && mapRight == nullptr) {
				mapLeft = stage[i];
				mapRight = stage[i];
			}
			if (mapLeft->Left() > stage[i]->Left()) mapLeft = stage[i];
			if (mapRight->Right() < stage[i]->Right()) mapRight = stage[i];
		}
		if (typeid(*stage[i]) == typeid(Player)) {
			player = stage[i];
		}
	}
}
void Camera::Update(Object *object[]) {
	float distance = 0;
	if ((player->Right() + player->Left()) / 2 != 640.0f / 2) {
		distance = (player->Right() + player->Left()) / 2 - 640.0f / 2;
	}
	if (distance < 0 && mapLeft->Left() < 0) {
		if (mapLeft->Left() - distance > 0) distance = mapLeft->Left();
		for (int i = 0; i < object[i]->object_num; i++) {
			object[i]->Set(object[i]->Left() - distance, object[i]->Top());
		}
	}
	if (distance > 0 && mapRight->Right() > 640.0f) {
		if (mapRight->Right() - distance < 640.0f) distance = mapRight->Right() - 640.0f;
		for (int i = 0; i < object[i]->object_num; i++) {//440
			object[i]->Set(object[i]->Left() - distance, object[i]->Top());
		}
	}
}