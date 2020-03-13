#include "Fps.h"
#include "DxLib.h"
Fps::Fps(){
	start_time_ = 0;
	count_ = 0;
}
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
		int took_time = GetNowCount() - start_time_;//60fps�o�߂ɂ�����������
		int wait_time = count_ * 1000 / FPS - took_time;//�{��60fps�ɂ�����\��̎��Ԃ�����ۂɂ����������Ԃ�����
		if (wait_time > 0) {
			Sleep(wait_time);//
		}
		return 0;
	}
	catch (...) {
		return -1;//�r���ŃG���[�����������ꍇ�A�Q�[�����I������
	}
}