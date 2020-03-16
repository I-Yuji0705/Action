#include "Keyboard.h"
#include "DxLib.h"

///<summary>
///<para>�󂯎�����L�[�R�[�h����A�Ώۂ̃L�[���ǂ̒��x������Ă��邩��Ԃ�</para>
///<para>����:</para>
///<param name="keycode"><para>keycode:���ׂ�L�[�R�[�h</para></param>
///<para>�߂�l:</para>
///<returns>
///<para>������keycode��������Ă���t���[����</para>
///</returns>
///</summary>
int Keyboard::CheckKey(int keycode) {
	return key[keycode];
}

///<summary>
///<para>�󂯎�����L�[�R�[�h����A�Ώۂ̃L�[���ǂ̒��x������Ă��邩��Ԃ�</para>
///<para>����:</para>
///<param name="keycode"><para>keycode:���ׂ�L�[�R�[�h</para></param>
///<para>�߂�l:</para>
///<returns>
///<para>0:�X�V����������</para>
///<para>-1:�X�V���ɃG���[����������</para>
///</returns>
///</summary>
int Keyboard::UpdateKey() {//�X�V�ɐ��������0��Ԃ��A�G���[���N�����-1��Ԃ�
	try
	{
		const int kKeyType =256;
		char tmpKey[kKeyType];
		GetHitKeyStateAll(tmpKey);//���ׂĂ�Key�̉�����Ԃ����
		for (int i = 0; i < kKeyType; i++) {
			if (tmpKey[i] != 0) key[i]++;//�L�[��������Ă����Ԃ̏ꍇ
			else key[i] = 0;
		}
		return 0;
	}
	catch (...)
	{
		return -1;
	}
}