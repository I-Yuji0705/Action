#pragma once
#include "BaseScene.h"
#include "TextData.h"
#include "ITitleStateChanger.h"
#include "CanvasBase.h"

//メニューのSceneクラス
class Title : public BaseScene ,ITitleStateChanger{
private:
	CanvasBase* titlecanvas_;
	TitleState nextstate_;//
	int title_;
	char stagename_[30];
public:
	Title(Keyboard* keyboard,Sound* sound,ISceneChanger* changer);
	void ChangeState(TitleState state);
	void ChangeState(TitleState state, const char stagename[30]);
	void Initialize() final;    //初期化処理
	void Update() final;        //更新処理
	void Draw() final;            //描画処理
	void Finalize() final;
	void StartBgm() final;
};
