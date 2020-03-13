#pragma once
#include "BaseScene.h"
#include "SelectionDeta.h"
#include "IManualStateChanger.h"
#include "ManualSelectionBase.h"

//マニュアルのSceneクラス
class Manual : public BaseScene, IManualStateChanger {
private:
	ManualSelectionBase* manualselection_;
	ManualState nextstate_;//
public:
	Manual(ISceneChanger* changer, Sound* sound);
	void ChangeState(ManualState state);
	void Initialize() final;    //初期化処理
	void Update() final;        //更新処理
	void Draw() final;            //描画処理
	void Finalize() final;	//終了処理
	void StartBgm() final; //BGMの再生処理
};