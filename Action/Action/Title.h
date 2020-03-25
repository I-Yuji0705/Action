#pragma once
#include "BaseScene.h"
#include "TextDeta.h"
#include "ITitleStateChanger.h"
#include "CanvasBase.h"

//メニューのSceneクラス
class Title : public BaseScene ,ITitleStateChanger{
private:
	CanvasBase* titlecanvas_;
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
