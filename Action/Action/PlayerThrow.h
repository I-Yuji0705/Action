#pragma once
#include "PlayerAction.h"

//Player�̓����鏈����S��������N���X
class PlayerThrow : public PlayerAction {
private:
	Sound* sound_;//�A�N�V�������ɖ炷��
public:
	PlayerThrow(Sound* sound, Player *player);
	void Do() final;
};