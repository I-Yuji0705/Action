#include "Keyboard.h"
#include "DxLib.h"
#define KeyNum 256//�L�[�̎��
int Keyboard::UpdateKey() {//�X�V�ɐ��������0��Ԃ��A�G���[���N�����-1��Ԃ�
	try
	{
		char tmpKey[KeyNum];
		GetHitKeyStateAll(tmpKey);
		for (int i = 0; i < KeyNum; i++) {
			if (tmpKey[i] != 0) key[i]++;
			else key[i] = 0;
		}
		return 0;
	}
	catch (...)
	{
		return -1;
	}
}
int Keyboard::CheckKey(int KeyCode) {
	return key[KeyCode];
}