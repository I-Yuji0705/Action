#pragma once
#include "Object.h"
class RelayPoint : public Object {
private:
	void Relay();
	float playerX,playerY;
	Object *player;
	bool pass;
public:
	void Update()override;
	void Draw() override;
	void Initialize(IStateChanger *stateChanger, Object** stage);
	bool Check(Object *player);
	void Retry() override;
	void Set(float x, float y, float height, float width, int objNum)override;
};