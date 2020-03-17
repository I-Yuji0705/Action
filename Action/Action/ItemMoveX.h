#pragma once
#include "ItemAction.h"
#include "Sound.h"
#include "Collision.h"
#include "ItemHit.h"

class Sound;
class Collision;
class ItemHit;

//Item‚ª“Š‚°‚ç‚ê‚Ä‚¢‚éÛ‚Ìs“®‚ÌŠî’êƒNƒ‰ƒX
class ItemMoveX : public ItemAction {
private:
	Sound* sound_;
	Collision* collision_;
	ItemHit* itemhit_;
	void MoveX(float num);
public:
	ItemMoveX(Sound* sound, Collision *collision, Item *item,ItemHit* itemhit);
	void Do() final;
};