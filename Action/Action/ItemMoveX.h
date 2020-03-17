#pragma once
#include "ItemAction.h"
#include "Sound.h"
#include "Collision.h"
#include "ItemHit.h"

class Sound;
class Collision;
class ItemHit;

//Item���������Ă���ۂ̍s���̊��N���X
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