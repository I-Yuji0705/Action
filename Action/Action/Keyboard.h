#pragma once
#include "Singleton.h"
class Keyboard : public Singleton<Keyboard>{
private:
	int key[256];
public:
	int CheckKey(int KeyCode);//�L�[�������Ă���t���[������Ԃ�
	int UpdateKey();//�L�[�̏�Ԃ��X�V����
};