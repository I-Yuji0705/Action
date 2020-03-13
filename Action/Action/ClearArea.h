#pragma once
#include "Object.h"
#include "Player.h"

//クリアの条件を満たす空間を担当する基底クラス
//この空間内をClearZone以外のObjectで満たすとクリアになる
class ClearArea :public Object {
private:
	std::vector<Object*> players_;
	Collision *collision_;
	bool clearstart_;
public:
	ClearArea(float x, float y, float height, float width,Sound* sound);
	void Initialize(IGameStateChanger *stateChanger, Collision *collision)final;
	void Update()final;
	void Draw()final;
};