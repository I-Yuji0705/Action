#pragma once
#include "Object.h"

enum  class BGM_Name {//BGMの種類
	BGM_Menu,//メニュー画面のBGM
	BGM_Game,//ゲーム画面のBGM
	BGM_Manual,//マニュアル画面のBGM

	BGM_None
};
enum class Se_Name {//SEの種類
	Se_Hit,//Objectが他のオブジェクトに接触した時のSe
	Se_Pick,//PlayerがItemを拾った際のSe
	Se_Throw,//PlayerがItemを投げた際のSe
	Se_Put,//PlayerがItemを置いた際のSe
	Se_Cant,//PlayerがThrow,Put,Pickを行う際に、その行動ができなかった時のSe
	Se_Jump,//Playerがジャンプし始めた時のSe
	Se_Clear,//ゲームをクリアした際のSe(ファンファーレ)
	Se_SceneChange,//シーンを変更している際に鳴らすSe

	Se_None
};
class Object;
//プログラム内のBGMとSEを管理する基底クラス
class Sound {
private:
	int bgm_[3];//BGM読み込み用
	int se_[8];//SE読み込み用
	int sevolume_[8];//SEの音量調整
	BGM_Name bgmname_; //現在鳴らしているBGM
	int RegulationSeVolume(Se_Name sename, const Object* object);
public:
	Sound();
	void PlayBgm(BGM_Name bgmname);
	void PlaySe(Se_Name sename);//オブジェクトの位置によらず音を鳴らす関数
	void PlaySe(Se_Name sename, const Object* object);//オブジェクトの位置によって鳴らす音の大きさを変える関数
	void StopSe();
	void StopBgm();
	void Finalize();
};