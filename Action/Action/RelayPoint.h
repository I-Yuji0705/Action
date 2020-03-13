#pragma once
#include "Object.h"
class RelayPoint : public Object {
private:
	float player_pos_x_,player_pos_y_;
	Object *player_;
	bool pass_;
	void Relay();
	bool Check(const Object *player);
public:
	RelayPoint(float x, float y, float height, float width, int object_type);
	void Initialize(IStateChanger *stateChanger,std::vector<Object*>& stage)override;
	void Update()override;
	void Draw() override;
	void Retry() override;
};