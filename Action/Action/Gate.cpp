#include "Gate.h"
#include <typeinfo.h>
#include "DxLib.h"
#include "Keyboard.h"
#include "Player.h"
//Gate“à‚Éplayer‚ª‘¶Ý‚µ‚Ä‚¢‚é‚©‚ð•Ô‚·
bool Gate::Check(Object *object) {
	bool check = false;
	if (Base() > player_->Top() && Top() < player_->Base() &&
		Right() > player_->Left() && Left() < player_->Right())
		check = true;
	return check;
}
Gate::Gate(float x, float y, float height, float width, int object_number) : Object(x, y, height, width, object_number) {
	switch (object_number_) {
	case 0:
		graph_handle_ = LoadGraph("Image/gate.png");
		quality_ = false;
		break;
	default:
		break;
	}
}

void Gate::Initialize(IStateChanger *stateChanger,std::vector<Object*>& stage) {
	Object::Initialize(stateChanger, stage);
	for (int i = 0; i != (*stage_).size(); i++) {
		if (typeid(*stage[i]) == typeid(Player)) {
			player_ = stage[i];
		}
	}
}
void Gate::Update() {
	if (Keyboard::getInstance()->CheckKey(KEY_INPUT_UP) == 1 && Check(player_) && player_->CanClear()) {
		player_->Set(x_, player_->Top());
		player_->Clear();
	}
}