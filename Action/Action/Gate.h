#pragma once
#include "Object.h"
#include "Player.h"
class Gate :public Object {
private:
	Object *player_;
	bool Check(Object *object);
public:
	Gate(float x, float y, float height, float width, int object_number);
	void Initialize(IStateChanger *stateChanger,std::vector<Object*>&stage)override;
	void Update()override;
};