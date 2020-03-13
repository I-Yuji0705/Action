#pragma once
#include "Object.h"

//ステージで地形を担当する基底クラス
class Terrain :public Object {
public:
	Terrain(float x, float y, float height, float width,Sound* sound);
	void Initialize(IGameStateChanger *stateChanger, Collision *collision);//初期化処理
	void Draw() override;
};