#pragma once
#include "Object.h"
#include "Collision.h"
#include <vector>

//Object‚ª‘¼‚ÌObject‚ÉÚG‚µ‚½Û‚Ìˆ—‚ğs‚¤’ŠÛƒNƒ‰ƒX
class Hit {
protected:
	Object *map_left_, *map_right_;
public:
	Hit(Collision *collision);
	virtual void HitObjects(int check, float distance) = 0;
};