#pragma once
#include "Object.h"
class Terrain :public Object {
private:
	bool damegeflg_;
public:
	Terrain(float x, float y, float height, float width, int object_number);
	//void Set(float x, float y, float height, float width, int object_number)override;
	void Draw() override;
};