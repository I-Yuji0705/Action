#include "Gate.h"
#include "DxLib.h"
#include "Player.h"
#include <typeinfo.h>
bool Gate::Check(Object *object) {
	bool check = false;
	if (Base() > player->Top() && Top() < player->Base() &&
		Right() > player->Left() && Left() < player->Right())
		check = true;
	return check;
}
void Gate::Set(float x, float y, float height, float width, int objNum) {
	Object::Set(x,y,height,width,objNum);
	switch (objNum) {
	case 0:
		graphHandle = LoadGraph("Image/gate.png");
		quality = false;
		break;
	default:
		break;
	}
}
void Gate::Initialize(IStateChanger *stateChanger, Object **stage) {
	Object::Initialize(stateChanger, stage);
	for (int i = 0; i < object_num; i++) {
		if (typeid(*stage[i]) == typeid(Player)) {
			player = stage[i];
		}
	}
}
void Gate::Update() {
	if (Keyboard::getInstance()->CheckKey(KEY_INPUT_UP) == 1 && Check(player)) {
		player->Set(x, player->Top());
		player->Clear();
	}
}