#pragma once

#include "Task.h"
#include "ISceneChanger.h"
//シーンの基底クラス。
enum StateMenu {
	State_Select,
	State_Delete,

};
class BaseScene : public Task {

protected:
	//int ImageHandle;                //画像ハンドル格納用変数
	ISceneChanger* SceneChanger;    //クラス所有元にシーン切り替えを伝えるインターフェイス
	struct MenuDeta {
		int x, y;
		char name[128];
	};
public:
	BaseScene(ISceneChanger* changer);
	virtual ~BaseScene() {}
	virtual void Initialize() override {}    //初期化処理をオーバーライド。
	virtual void Finalize() override;        //終了処理をオーバーライド。
	virtual void Update() override {}       //更新処理をオーバーライド。
	virtual void Draw() override {}            //描画処理をオーバーライド。
};
