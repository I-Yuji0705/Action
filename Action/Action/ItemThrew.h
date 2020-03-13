#pragma once
#include "ItemAction.h"

//Item‚ª“Š‚°‚ç‚ê‚Ä‚¢‚éÛ‚Ìs“®‚ÌŠî’êƒNƒ‰ƒX
class ItemThrew : public ItemAction {
private:
	Sound* sound_;
	Collision* collision_;
	ItemHit* itemhit_;
	void MoveX(float num);
public:
	ItemThrew(Sound* sound, Collision *collision, Item *item,ItemHit* itemhit);
	void Do() final;
};