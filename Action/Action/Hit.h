#pragma once
#include "Object.h"
#include "Collision.h"
#include <vector>

//Object������Object�ɐڐG�����ۂ̏������s�����ۃN���X
class Hit {
protected:
	Object *map_left_, *map_right_;
public:
	Hit(Collision *collision);
	virtual void HitObjects(int check, float distance) = 0;
};