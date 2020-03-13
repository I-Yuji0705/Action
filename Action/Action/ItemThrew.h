#pragma once
#include "ItemAction.h"

//Item‚ª“Š‚°‚ç‚ê‚Ä‚¢‚éÛ‚Ìs“®‚ÌŠî’êƒNƒ‰ƒX
class ItemThrew : public ItemAction {
private:
	const float kThrowSpeed = 10.0f;
	void MoveX(float num);
public:
	ItemThrew(Collision* collision, Item* item, Sound* sound);
	void Do() final;
};