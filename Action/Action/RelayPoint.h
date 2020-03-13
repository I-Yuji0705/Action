#pragma once
#include "Object.h"
class RelayPoint : public Object {
private:
	float playerX,playerY;
	Object *player;
	bool pass;
	void Relay();
	bool Check(Object *player);
public:
	void Set(float x, float y, float height, float width, int objNum)override;
	void Initialize(IStateChanger *stateChanger, Object *stage[])override;
	void Update()override;
	void Draw() override;
	void Retry() override;
};