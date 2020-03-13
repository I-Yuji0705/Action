#include "RelayPoint.h"
#include <typeinfo.h>
#include "Player.h"
void RelayPoint::Relay() {
	playerX = retryX;
	playerY = player->Top();
	pass = true;
}
bool RelayPoint::Check(Object *player) {
	bool check = false;
	if (Base() > player->Top() && Top() < player->Base() && Right() > player->Left() && Left() < player->Right())
		check = true;
	return check;
}
void RelayPoint::Set(float x, float y, float height, float width, int objNum) {
	Object::Set(x, y, height, width, objNum);
	quality = false;
}
void RelayPoint::Initialize(IStateChanger *stateChanger, Object *stage[]) {
	Object::Initialize(stateChanger, stage);
	pass = false;
	for (int i = 0; i < object_num; i++) {
		if (typeid(*stage[i]) == typeid(Player)) {
			player = stage[i];
		}
	}
}
void RelayPoint::Update() {
	if (Check(player) && !pass) {
		Relay();
	}

}
void RelayPoint::Draw() {
}
void RelayPoint::Retry() {
	Object::Retry();
	if(pass)player->RelaySet(playerX, playerY);
}