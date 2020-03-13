#pragma once
#include "BaseScene.h"
class Menu : public BaseScene {
private:
	int MenuNum;
	MenuDeta menudeta[2];
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
