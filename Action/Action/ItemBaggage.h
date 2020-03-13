#pragma once
#include "ItemAction.h"

//Item‚ªPlayer‚É‚½‚ê‚Ä‚¢‚éÛ‚És‚¤Šî’êƒNƒ‰ƒX
class ItemBaggage : public ItemAction {
public:
	ItemBaggage(Collision * collision, Item* item_, Sound* sound);
	void Do() final;
};