#pragma once
#include "ISceneChanger.h"
//シーンの基底クラス。
enum StateMenu {
	State_Select,
	State_Delete,
};
class BaseScene {

protected:
	ISceneChanger* SceneChanger;    //クラス所有元にシーン切り替えを伝えるインターフェイス
	struct MenuDeta {
		int x, y;
		char name[128];
	};
public:
	BaseScene(ISceneChanger* changer);
	virtual void Initialize() {};    //初期化処理をオーバーライド
	virtual void Finalize();        //終了処理をオーバーライド
	virtual void Update() {};       //更新処理をオーバーライド
	virtual void Draw() {};            //描画処理をオーバーライド
};
