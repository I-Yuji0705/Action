#pragma once
#include "PlayerAction.h"
#include "Gravity.h"
#include "Keyboard.h"
#include "PlayerHit.h"

class Keyboard;
class Collison;
class Sound;
class PlayerHit;

//Player��Y���̈ړ���S�����钊�ۃN���X
class PlayerMoveY : public PlayerAction {
protected:
	Keyboard *keyboard_;
	Collision* collision_;//�A�N�V�������̕���������v������ꏊ
	Sound* sound_;//�A�N�V�������ɖ炷��
	PlayerHit* playerhit_;
	Gravity gravity_;
	const float kJumpPower = 8.0f;//Jump���̊�b���x
	void MoveY(float num);
public:
	PlayerMoveY(Keyboard* keyboard,Sound* sound, Collision *collision, Player *player,PlayerHit* hit);
	void Do() override;
};