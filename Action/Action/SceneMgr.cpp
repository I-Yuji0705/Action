#include "SceneMgr.h"
#include "DxLib.h"
#include "Title.h"
#include "Game.h"
#include "Manual.h"
#include <assert.h>

SceneMgr::SceneMgr(Keyboard* keyboard,Sound* sound) : next_scene_(Scene_None) //次のシーン管理変数
{
	keyboard_ = keyboard;
	sound_ = sound;
	scene_ = (BaseScene*) new Title(keyboard_, sound_, this);
	//scene_->StartBgm();
	state = Normal_Scene;
}

//初期化
void SceneMgr::Initialize() {
	scene_->Initialize();
}

//終了処理
void SceneMgr::Finalize() {
	scene_->Finalize();
	sound_->Finalize();
}

//更新
void SceneMgr::Update() {
	switch (state) {
	case Normal_Scene:
		if (next_scene_ != Scene_None) {    //次のシーンがセットされていたら
			state = BlackOut_Scene;
			sound_->StopBgm();
			sound_->StopSe();
			sound_->PlaySe(Se_SceneChange);
		}
		scene_->Update(); //シーンの更新
		break;
	case BlackOut_Scene:
		BlackOutScene();
		break;
	case Lighting_Scene:
		LightingScene();
		break;
	default:
		assert(false);
		break;
	}
}

//描画
void SceneMgr::Draw() {
	scene_->Draw(); //シーンの描画
}

// 引数 nextScene にシーンを変更する
void SceneMgr::ChangeScene(Scene nextscene) {
	next_scene_ = nextscene;    //次のシーンをセットする
	SetDepictionScreen(0, 0, 640, 480);
}
void SceneMgr::BlackOutScene() {
	const int animationspeed = 2;
	SetDepictionScreen(screen.x1 + animationspeed * 3, screen.y1 + animationspeed * 4, screen.x2 - animationspeed * 3, screen.y2 - animationspeed * 4);
	if (screen.x1 > screen.x2 || screen.y1 > screen.y2) {
		state = Lighting_Scene;
		scene_->Finalize();//現在のシーンの終了処理を実行
		delete scene_;
		switch (next_scene_) {       //シーンによって処理を分岐
		case Scene_Title:        //次の画面がメニューなら
			scene_ = (BaseScene*) new Title(keyboard_, sound_,this);   //メニュー画面のインスタンスを生成する
			break;
		case Scene_Game:        //次の画面がゲームなら
			scene_ = (BaseScene*) new Game(keyboard_, sound_, this);   //ゲーム画面のインスタンスを生成する
			break;
		case Scene_Manual:        //次の画面がマニュアルなら
			scene_ = (BaseScene*) new Manual(keyboard_, sound_, this);   //マニュアル画面のインスタンスを生成する
			break;
		default:
			assert(false);
			break;
		}
		next_scene_ = Scene_None;    //次のシーン情報をクリア
		scene_->Initialize();    //シーンを初期化
	}
}
void SceneMgr::LightingScene() {
	const int animationspeed = 2;
	SetDepictionScreen(screen.x1 - animationspeed * 3, screen.y1 - animationspeed * 4, screen.x2 + animationspeed * 3, screen.y2 + animationspeed * 4);
	if (screen.x1 < 0 && screen.x2 > 480 && screen.y1 < 0 && screen.y2 > 640) { 
		state = Normal_Scene; 
		//scene_->StartBgm();
	}
}
void SceneMgr::SetDepictionScreen(int x1, int y1, int x2, int y2) {
	screen.x1 = x1;
	screen.y1 = y1;
	screen.x2 = x2;
	screen.y2 = y2;
	SetDrawArea(screen.x1, screen.y1, screen.x2, screen.y2);
}