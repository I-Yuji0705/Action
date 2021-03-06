#pragma once
#include "Object.h"
#include "Collision.h"
#include <vector>

//Objectが他のObjectに接触した際の処理を行う抽象クラス
class Hit {
protected:
	Object *map_left_, *map_right_;
public:
	Hit(Collision *collision);
	virtual void HitObjects(int check, float distance) = 0;
};