#pragma once
#include "Object.h"
#include "Player.h"
class Gate :public Object {
private:
	Object *player;
	bool Check(Object *object);
public:
	void Set(float x, float y, float height, float width, int objNum)override;
	void Initialize(IStateChanger *stateChanger, Object** stage);
	void Update()override;
};