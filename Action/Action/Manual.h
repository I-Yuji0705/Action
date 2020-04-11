#pragma once
#include "BaseScene.h"
#include "TextData.h"
#include "IManualStateChanger.h"
#include "ManualCanvasBase.h"

//マニュアルのSceneクラス
class Manual : public BaseScene, IManualStateChanger {
private:
	CanvasBase* manualcanvas_;
	ManualState nextstate_;//
public:
	Manual(Keyboard* keyboard, Sound* sound,ISceneChanger* changer);
	void ChangeState(ManualState state);
	void Initialize() final;    //初期化処理
	void Update() final;        //更新処理
	void Draw() final;            //描画処理
	void Finalize() final;	//終了処理
	void StartBgm() final; //BGMの再生処理
};