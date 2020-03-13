#pragma once
#include "Object.h"
#include "Player.h"
#include "ColorCode.h"

//クリアの条件を満たす空間を担当する基底クラス
//この空間内をClearZone以外のObjectで満たすとクリアになる
class ClearArea :public Object {
private:
	unsigned int color_;
	Sound* sound_;
	std::vector<Object*> players_;
	Collision *collision_;
	bool clearstart_;
public:
	ClearArea(Sound* sound, Collision* collision,ColorCode color, float x, float y, float height, float width);
	void Initialize()final;
	void Update()final;
	void Draw()final;
};