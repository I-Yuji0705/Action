#include "Fps.h"
#include "DxLib.h"

///<summary>
///<para>�R���X�g���N�^</para>
///<para>�J�n���ԂƃJ�E���g�̏����l�ݒ�</para>
///</summary>
Fps::Fps(){
	start_time_ = 0;
	count_ = 0;
}

///<summary>
///<para>�X�V����</para>
///<para>Fps��60��荂���ꍇ�A60�ɂ��낦��</para>
///<para>�߂�l:</para>
///<returns>
///<para>0:�X�V����</para>
///<para>-1:��������̃G���[����</para>
///</returns>
///</summary>
int Fps::Update() {
	try {
		if (count_ == 0) { 
			start_time_ = GetNowCount(); 
		}
		const int FPS = 60;
		if (count_ == FPS){
			count_ = 0;
			start_time_ = GetNowCount();
		}
		count_++;
		int took_time = GetNowCount() - start_time_;//60fps�o�߂ɂ�����������
		int wait_time = count_ * 1000 / FPS - took_time;//�{��60fps�ɂ�����\��̎��Ԃ�����ۂɂ����������Ԃ�����
		if (wait_time > 0) {
			Sleep(wait_time);//60fps�ɂ�����\��̎��Ԃ܂Ńv���O�������~����
		}
		return 0;
	}
	catch (...) {
		return -1;//�r���ŃG���[�����������ꍇ�A�Q�[�����I������
	}
}