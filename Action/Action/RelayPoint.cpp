#include "RelayPoint.h"
#include <typeinfo.h>
#include "Player.h"
RelayPoint::RelayPoint(float x, float y, float height, float width, int object_type) :Object(x ,y ,height ,width ,object_type ) {
	quality_ = false;
}
void RelayPoint::Relay() {
	player_pos_x_ = retry_pos_x_;
	retry_pos_y_ = player_->Top();
	pass_ = true;
}
bool RelayPoint::Check(const Object *player) {
	bool check = false;
	if (Base() > player->Top() && Top() < player->Base() && Right() > player->Left() && Left() < player->Right())
		check = true;
	return check;
}

void RelayPoint::Initialize(IStateChanger *stateChanger, std::vector<Object*>& stage) {
	Object::Initialize(stateChanger, stage);
	pass_ = false;
	for (int i = 0; i != (*stage_).size(); i++) {
		if (typeid(*stage[i]) == typeid(Player)) {
			player_ = stage[i];
		}
	}
}
void RelayPoint::Update() {
	if (Check(player_) && !pass_) {
		Relay();
	}

}
void RelayPoint::Draw() {
}
void RelayPoint::Retry() {
	Object::Retry();
	if(pass_)player_->RelaySet(player_pos_x_, retry_pos_y_);
}