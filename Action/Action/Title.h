#pragma once
#include "BaseScene.h"
#include "SelectionDeta.h"
#include "ITitleStateChanger.h"
#include "TitleSelectionBase.h"

//メニューのSceneクラス
class Title : public BaseScene ,ITitleStateChanger{
private:
	TitleSelectionBase* titleselection_;
	TitleState nextstate_;//
	int title_;
public:
	Title(Keyboard* keyboard,Sound* sound,ISceneChanger* changer);
	void ChangeState(TitleState state);
	void Initialize() final;    //初期化処理
	void Update() final;        //更新処理
	void Draw() final;            //描画処理
	void Finalize() final;
	void StartBgm() final;
};
