#pragma once
#include "PlayerAction.h"
#include "Gravity.h"
//Player��Y���̈ړ���S�����钊�ۃN���X
class PlayerMoveY : public PlayerAction {
protected:
	Gravity gravity_;
	Collision* collision_;//�A�N�V�������̕���������v������ꏊ
	Sound* sound_;//�A�N�V�������ɖ炷��
	PlayerHit* playerhit_;
	void MoveY(float num);
public:
	PlayerMoveY(Sound* sound, Collision *collision, Player *player,PlayerHit* hit);
};