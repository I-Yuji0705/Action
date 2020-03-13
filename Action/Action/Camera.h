#pragma once
#include "Object.h"
#include "Terrain.h"
#include "Player.h"
class Camera {
private:
	//Terrain *mapLeft, *mapRight;//マップの左端と右端の地形
	Object *mapLeft, *mapRight;
public:
	//void Initialize(Terrain *terrain);
	void Initialize(Object *stage[]);
	void Update(Object *object[], Player *player);
};