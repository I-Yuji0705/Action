#pragma once

//�L�[�{�[�h�̏�Ԃ�
//�L�[�������Ă��鎞�Ԃ�Ԃ��N���X
class Keyboard {
private:
	int key[256];
public:
	int CheckKey(int KeyCode);//�L�[�������Ă���t���[������Ԃ�
	int UpdateKey();//�L�[�̏�Ԃ��X�V����
};