#include "Fps.h"
#include "DxLib.h"

///<summary>
///<para>コンストラクタ</para>
///<para>開始時間とカウントの初期値設定</para>
///</summary>
Fps::Fps(){
	start_time_ = 0;
	count_ = 0;
}

///<summary>
///<para>更新処理</para>
///<para>Fpsが60より高い場合、60にそろえる</para>
///<para>戻り値:</para>
///<returns>
///<para>0:更新完了</para>
///<para>-1:何かしらのエラー発生</para>
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
		int took_time = GetNowCount() - start_time_;//60fps経過にかかった時間
		int wait_time = count_ * 1000 / FPS - took_time;//本来60fpsにかかる予定の時間から実際にかかった時間を引く
		if (wait_time > 0) {
			Sleep(wait_time);//60fpsにかかる予定の時間までプログラムを停止する
		}
		return 0;
	}
	catch (...) {
		return -1;//途中でエラーが発生した場合、ゲームを終了する
	}
}