#pragma once
#include "Object.h"
class Terrain :public Object {
private:
public:
	bool damegeflg;
	static int terrain_num;
	void Set(float x, float y, float height, float width, int objNum);
	void Update();
};