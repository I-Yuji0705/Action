#pragma once
#include "ItemAction.h"

//Item���������Ă���ۂ̍s���̊��N���X
class ItemThrew : public ItemAction {
private:
	const float kThrowSpeed = 10.0f;
	void MoveX(float num);
public:
	ItemThrew(Collision* collision, Item* item, Sound* sound);
	void Do() final;
};