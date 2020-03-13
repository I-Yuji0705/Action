#include "Keyboard.h"
#include "DxLib.h"
int Keyboard::CheckKey(int keycode) {
	return key[keycode];
}
int Keyboard::UpdateKey() {//�X�V�ɐ��������0��Ԃ��A�G���[���N�����-1��Ԃ�
	try
	{
		const int kKeyType =256;
		char tmpKey[kKeyType];
		GetHitKeyStateAll(tmpKey);
		for (int i = 0; i < kKeyType; i++) {
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