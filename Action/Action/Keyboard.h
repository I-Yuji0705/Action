#pragma once
#include "Singleton.h"

//�L�[�{�[�h�̏�Ԃ�
//�L�[�������Ă��鎞�Ԃ�Ԃ��N���X
class Keyboard : public Singleton<Keyboard>{
private:
	int key[256];
public:
	int CheckKey(int KeyCode);//�L�[�������Ă���t���[������Ԃ�
	int UpdateKey();//�L�[�̏�Ԃ��X�V����
};