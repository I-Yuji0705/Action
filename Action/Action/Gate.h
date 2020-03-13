#pragma once
#include "Object.h"
#include "Player.h"
class Gate :public Object {
private:
	Object *player;
public:
	bool Check(Player *player);
	void Set(float x, float y, float height, float width, int objNum)override;
	void Update(Player *player);
	void Update()override;
	bool Check(Object *object);
	void Initialize(IStateChanger *stateChanger, Object** stage);
	//void Draw()override;
};