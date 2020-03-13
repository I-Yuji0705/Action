#pragma once
#include "Hit.h"
#include "Item.h"

class Item;

//Item�����̃I�u�W�F�N�g�ɐڐG�������̑����S��������N���X
class ItemHit : public Hit {
private:
	Item* item_;
public:
	ItemHit(Collision* collision,Item* item);
	void HitProcess(int hitcheck, Object* hitobject)final;
	void MapHit(int mapcheck)final;
};