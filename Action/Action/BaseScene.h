#pragma once
#include "ISceneChanger.h"
#include "Sound.h"
//プログラム内のシーンの基底クラス
class BaseScene {

protected:
	ISceneChanger* SceneChanger;    //クラス所有元にシーン切り替えを伝えるインターフェイス
	Sound* sound_;
public:
	BaseScene(ISceneChanger* changer,Sound* sound);
	virtual void Initialize() {};    //初期化処理
	virtual void Finalize();        //終了処理
	virtual void Update() {};       //更新処理
	virtual void Draw() {};            //描画処理
	virtual void StartBgm() = 0; //Scene毎に鳴らすbgmの設定
};
