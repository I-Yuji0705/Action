#pragma once
#include "PlayerAction.h"

//Player�̏E��������S��������N���X
class PlayerPick : public PlayerAction {
private:
	Collision* collision_;//�A�N�V�������̕���������v������ꏊ
	Sound* sound_;//�A�N�V�������ɖ炷��
public:
	PlayerPick(Sound* sound, Collision *collision, Player *player);
	void Do() final;
};