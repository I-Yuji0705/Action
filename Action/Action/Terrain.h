#pragma once
#include "Object.h"

//ステージで地形を担当する基底クラス
class Terrain :public Object {
public:
	Terrain(float x, float y, float height, float width);
	void Draw() override;
};