#include "Camera.h"
#include "DxLib.h"
#include <typeinfo.h>

void Camera::Initialize(std::vector<Object*> stage) {
	map_left_, map_right_ = nullptr;
	stage_ = stage;
	for (auto i : stage_) {
		if (typeid(*i) == typeid(Terrain)) {
			if (map_left_ == nullptr) map_left_ = i;
			else if (map_left_->Left() > i->Left()) map_left_ = i;
			if (map_right_ == nullptr) map_right_ = i;
			else if (map_right_->Right() < i->Right()) map_right_ = i;
		}
		if (typeid(*i) == typeid(Player)) {
			player_ = i	;
		}
	}
}

void Camera::Update(){
	float distance = 0;
	const float kWindowX = 640.0f;
	if ((player_->Right() + player_->Left()) / 2 != kWindowX / 2) {
		distance = (player_->Right() + player_->Left()) / 2 - kWindowX / 2;
	}	
	if (distance < 0 && map_left_->Left() < 0) {
		if (map_left_->Left() - distance > 0) distance = map_left_->Left();
		for (auto i : stage_) {
			i->Set(i->Left() - distance,i->Top());
		}
	}
	if (distance > 0 && map_right_->Right() > kWindowX) {
		if (map_right_->Right() - distance < kWindowX) distance = map_right_->Right() - kWindowX;
		for (auto i : stage_) {
			i->Set(i->Left() - distance, i->Top());
		}
	}
	
}