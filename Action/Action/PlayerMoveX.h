#pragma once
#include "PlayerAction.h"
#include <vector>
//Player��X���̈ړ���S�����钊�ۃN���X
class PlayerMoveX : public PlayerAction {
protected:
	const float kMoveSpeed = 5.0f;//Player�̉��ړ��̑��x
	void MoveX(float num);//Player�̈ړ�
	bool Push(float num,std::vector<Object*> target);//�ړ����Object�������o���A�����o��������Ԃ�
private:
	bool firsthit_;//�ڐG���n�߂������m�F����ϐ�
public:
	PlayerMoveX(Collision *collision, Player *playe, Sound* sound);
	//virtual void Do()override = 0;
};