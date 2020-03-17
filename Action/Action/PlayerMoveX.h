#pragma once
#include "PlayerAction.h"
#include <vector>
#include "Keyboard.h"
#include "PlayerHit.h"

class Keyboard;
class Collison;
class Sound;
class PlayerHit;

//Player��X���̈ړ���S�����钊�ۃN���X
class PlayerMoveX : public PlayerAction {
protected:
	Keyboard *keyboard_;
	Collision* collision_;//�A�N�V�������̕���������v������ꏊ
	Sound* sound_;//�A�N�V�������ɖ炷��
	PlayerHit* playerhit_;
	const float kMoveSpeed = 5.0f;//Player�̉��ړ��̑��x
	void MoveX(float num);//Player�̈ړ�
	bool Push(float num, std::vector<Object*> target, int check);//�ړ����Object�������o���A�����o��������Ԃ�
private:
	bool firsthit_;//�ڐG���n�߂������m�F����ϐ�
public:
	PlayerMoveX(Keyboard* keyboard,Sound* sound, Collision *collision, Player *player,PlayerHit* hit);
	void Do() override;
};