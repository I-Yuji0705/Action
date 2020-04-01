#pragma once
#include "ISceneChanger.h"
#include "Sound.h"
#include "Keyboard.h"
class Keyboard;
class Sound;
//プログラム内のシーンの基底クラス
class BaseScene {
protected:
	Keyboard* keyboard_;
	Sound* sound_;
	ISceneChanger* scenechanger_;    //クラス所有元にシーン切り替えを伝えるインターフェイス
public:
	BaseScene(Keyboard* keyboard,Sound* sound,ISceneChanger* changer);
	virtual void Initialize() {};    //初期化処理
	virtual void Finalize() {};        //終了処理
	virtual void Update() {};       //更新処理
	virtual void Draw() {};            //描画処理
	virtual void StartBgm() = 0; //Scene毎に鳴らすbgmの設定
};
