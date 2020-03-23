#include "SceneMgr.h"
#include "DxLib.h"
#include "Title.h"
#include "Game.h"
#include "Manual.h"
#include <assert.h>

///<summary>
///<para>コンストラクタ</para>
///<para>Scene内で使用するキーボードクラスと音を発生させるクラスを取得する</para>
///<para>追加で、最初のSceneをTitleに設定する</para>
///<para>引数:</para>
///<param name= "keyboard"><para>キーが押されているか確認するクラス</para></param>
///<param name= "sound"><para>BGMやSEなどの音を発生させるクラス</para></param>
///</summary>
SceneMgr::SceneMgr(Keyboard* keyboard,Sound* sound) : next_scene_(Scene_None) //次のシーン管理変数
{
	keyboard_ = keyboard;
	sound_ = sound;
	scene_ = (BaseScene*) new Title(keyboard_, sound_, this);
	//scene_->StartBgm();
	state = Normal_Scene;
}

//初期化
///<summary>
///<para>初期化処理</para>
///<para>Sceneの初期化処理を行う</para>
///</summary>
void SceneMgr::Initialize() {
	scene_->Initialize();
}

//終了処理
///<summary>
///<para>終了処理</para>
///<para>Sceneの終了処理を行う</para>
///</summary>
void SceneMgr::Finalize() {
	scene_->Finalize();
	sound_->Finalize();
}

//更新
///<summary>
///<para>更新処理</para>
///<para>Sceneの変更要請がない場合、Sceneの更新処理を行う</para>
///<para>Sceneの変更要請があった場合、画面を暗くし始める</para>
///</summary>
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

///<summary>
///<para>描写処理</para>
///<para>Sceneの描写処理を行う</para>
///</summary>
void SceneMgr::Draw() {
	scene_->Draw(); //シーンの描画
}

// 引数 nextScene にシーンを変更する

///<summary>
///<para>シーンの変更処理</para>
///<para>次のシーンをセットし、描写範囲を設定しなおす</para>
///</summary>
void SceneMgr::ChangeScene(Scene nextscene) {
	next_scene_ = nextscene;    //次のシーンをセットする
	SetDepictionScreen(0, 0, 640, 480);
}

///<summary>
///<para>シーンの暗転処理</para>
///<para>描写範囲を狭めることで画面を暗くする</para>
///<para>描写範囲を無くした後、シーンの変更処理を行い、Stateを暗転の状態から明るくする状態に変更する</para>
///</summary>
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

///<summary>
///<para>シーンの明るくする処理</para>
///<para>描写範囲を広げることで画面を明るくする</para>
///<para>描写範囲を画面まで広げた後、Scene毎のBGMを再生し、Stateを通常時に変更する</para>
///</summary>
void SceneMgr::LightingScene() {
	const int animationspeed = 2;
	SetDepictionScreen(screen.x1 - animationspeed * 3, screen.y1 - animationspeed * 4, screen.x2 + animationspeed * 3, screen.y2 + animationspeed * 4);
	if (screen.x1 < 0 && screen.x2 > 480 && screen.y1 < 0 && screen.y2 > 640) { 
		state = Normal_Scene;
		SetDepictionScreen(0, 0, 640, 480);
		//scene_->StartBgm();
	}
}

///<summary>
///<para>シーンの描写範囲の変更処理</para>
///<para>描写する範囲の左上のX座標とY座標、右下のX座標とY座標を引数として受け取る</para>
///<para>シーンの描写範囲を変数に保存した後、受け取った座標を対角線とする四角形を描写範囲として設定する</para>
///<para>引数:</para>
///<param name="x1"><para>x1:描写する範囲の左上のX座標</para></param>
///<param name="y1"><para>y1:描写する範囲の左上のY座標</para></param>
///<param name="x2"><para>x2:描写する範囲の右下のX座標</para></param>
///<param name="y2"><para>y2:描写する範囲の右下のX座標</para></param>
///</summary>
void SceneMgr::SetDepictionScreen(int x1, int y1, int x2, int y2) {
	screen.x1 = x1;
	screen.y1 = y1;
	screen.x2 = x2;
	screen.y2 = y2;
	SetDrawArea(screen.x1, screen.y1, screen.x2, screen.y2);
}