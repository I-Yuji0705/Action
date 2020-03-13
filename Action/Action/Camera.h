#pragma once
#include "Object.h"
#include "Terrain.h"
class Camera {
private:
	Object *mapLeft, *mapRight;
	Object *player;
public:
	void Initialize(Object *stage[]);
	void Update(Object *object[]);
};