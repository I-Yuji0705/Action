#pragma once
#include "PlayerAction.h"

//Player�̒u��������S��������N���X
class PlayerPut : public PlayerAction {
private:
	Sound* sound_;//�A�N�V�������ɖ炷��
public:
	PlayerPut(Sound* sound, Player *player);
	void Do() final;
};