#pragma once
#include "BaseScene.h"
//enum StateMenu {
//	State_Select,
//	State_Delete,
//
//};
//メニュー画面クラス
class Menu : public BaseScene {
private:
	int MenuNum;
	MenuDeta menudeta[3];
	MenuDeta deletemessage[2]; 
	StateMenu state;//
	void SelectMenu();//メニュー処理
	void SelectDelete();//終了確認
	int DeleteNum;
public:
	Menu(ISceneChanger* changer);
	void Initialize() override;    //初期化処理をオーバーライド。
	void Update() override;        //更新処理をオーバーライド。
	void Draw() override;            //描画処理をオーバーライド。
};
