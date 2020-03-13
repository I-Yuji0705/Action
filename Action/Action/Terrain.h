#pragma once
#include "Object.h"
class Terrain :public Object {
private:
	bool damegeflg;
public:
	void Set(float x, float y, float height, float width, int objNum)override;
};