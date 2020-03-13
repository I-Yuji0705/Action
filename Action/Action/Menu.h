#pragma once
#include "BaseScene.h"
#include "SelectionDeta.h"
#include "IMenuStateChanger.h"
#include "MenuSelectionBase.h"

//メニューのSceneクラス
class Menu : public BaseScene ,IMenuStateChanger{
private:
	MenuSelectionBase* menuselection_;
	MenuState nextstate_;//
	int title_;
public:
	Menu(Keyboard* keyboard,Sound* sound,ISceneChanger* changer);
	void ChangeState(MenuState state);
	void Initialize() final;    //初期化処理
	void Update() final;        //更新処理
	void Draw() final;            //描画処理
	void Finalize() final;
	void StartBgm() final;
};
