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
		int took_time = GetNowCount() - start_time_;//60fps経過にかかった時間
		int wait_time = count_ * 1000 / FPS - took_time;//本来60fpsにかかる予定の時間から実際にかかった時間を引く
		if (wait_time > 0) {
			Sleep(wait_time);//
		}
		return 0;
	}
	catch (...) {
		return -1;//途中でエラーが発生した場合、ゲームを終了する
	}
}