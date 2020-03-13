#pragma once
#include "Object.h"
#include "Collision.h"

//Object‚ª‘¼‚ÌObject‚ÉÚG‚µ‚½Û‚Ìˆ—‚ğs‚¤’ŠÛƒNƒ‰ƒX
class Hit {
protected:
	Object *map_left_, *map_right_;
public:
	Hit(Collision *collision);
	virtual void HitProcess(int hitcheck,Object* hitobject) = 0;
	virtual void MapHit(int mapcheck) = 0;
};