#pragma once
#include <vector>
#include "Object.h"
#include "Terrain.h"
#include "Player.h"
#include "Collision.h"

//ゲーム内でPlayerを中心に写すためにステージの調整を行うクラス
class Camera {
private:
	Object *map_left_, *map_right_;//ステージ左端、右端にある地形Object
	Object *player_;//中心に写す対象のObject
	std::vector<Object*> stage_;//ステージ

public:
	void Initialize(std::vector<Object*> stage, Collision* collision);
	void Update();
};