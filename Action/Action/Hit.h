#pragma once
#include "Object.h"
#include "Collision.h"

//Object������Object�ɐڐG�����ۂ̏������s�����ۃN���X
class Hit {
protected:
	Object *map_left_, *map_right_;
public:
	Hit(Collision *collision);
	virtual void HitProcess(int hitcheck,Object* hitobject) = 0;
	virtual void MapHit(int mapcheck) = 0;
};