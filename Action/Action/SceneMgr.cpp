#include "SceneMgr.h"
#include "DxLib.h"
#include "Menu.h"
#include "Game.h"
SceneMgr::SceneMgr() : NextScene(Scene_None) //次のシーン管理変数
{
	scene = (BaseScene*) new Menu(this);
}

//初期化
void SceneMgr::Initialize() {
	scene->Initialize();
}

//終了処理
void SceneMgr::Finalize() {
	scene->Finalize();
}

//更新
void SceneMgr::Update() {
	if (NextScene != Scene_None) {    //次のシーンがセットされていたら
		scene->Finalize();//現在のシーンの終了処理を実行
		delete scene;
		switch (NextScene) {       //シーンによって処理を分岐
		case Scene_Menu:        //次の画面がメニューなら
			scene = (BaseScene*) new Menu(this);   //メニュー画面のインスタンスを生成する
			break;//以下略
		case Scene_Game:        //次の画面がメニューなら
			scene = (BaseScene*) new Game(this);   //メニュー画面のインスタンスを生成する
			break;//以下略
		}
		
		NextScene = Scene_None;    //次のシーン情報をクリア
		scene->Initialize();    //シーンを初期化
	}

	scene->Update(); //シーンの更新
}

//描画
void SceneMgr::Draw() {
	scene->Draw(); //シーンの描画
}

// 引数 nextScene にシーンを変更する
void SceneMgr::ChangeScene(Scene nextScene) {
	NextScene = nextScene;    //次のシーンをセットする
}