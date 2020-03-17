#pragma once
#include "PlayerAction.h"

class Keyboard;
class Collison;
class Sound;

//Playerの持つ、置く、投げる処理を管理する基底クラス
class PlayerActionBaggage : public PlayerAction {
private:
	Keyboard *keyboard_;
	Collision* collision_;//アクション時の物理判定を計測する場所
	Sound* sound_;//アクション時に鳴らす音
	void Pick();
	void Throw();
	void Put();
public:
	PlayerActionBaggage(Keyboard* keyboard, Sound* sound, Collision *collision, Player *player);
	void Do() final;
};