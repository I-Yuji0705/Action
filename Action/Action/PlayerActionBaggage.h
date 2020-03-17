#pragma once
#include "PlayerAction.h"

class Keyboard;
class Collison;
class Sound;

//Player�̎��A�u���A�����鏈�����Ǘ�������N���X
class PlayerActionBaggage : public PlayerAction {
private:
	Keyboard *keyboard_;
	Collision* collision_;//�A�N�V�������̕���������v������ꏊ
	Sound* sound_;//�A�N�V�������ɖ炷��
	void Pick();
	void Throw();
	void Put();
public:
	PlayerActionBaggage(Keyboard* keyboard, Sound* sound, Collision *collision, Player *player);
	void Do() final;
};