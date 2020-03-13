#pragma once
#include <vector>
#include "Object.h"
#include "Terrain.h"
#include "Player.h"
class Camera {
private:
	Object *map_left_, *map_right_;
	Object *player_;
	std::vector<Object*> stage_;

public:
	void Initialize(std::vector<Object*> stage);
	void Update();
};