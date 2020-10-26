#include "Game.h"
#include "DxLib.h"
#include "Keyboard.h"
#include "GameClear.h"
#include "GameUsually.h"
#include "GameMenu.h"
#include "GameDance.h"
#include <assert.h>
#include <typeinfo>


///<summary>
///<para>コンストラクタ</para>
///<para>最初に表示する字幕とステージを管理するクラスの生成</para>
///</summary>
Game::Game(Keyboard* keyboard, Sound* sound,ISceneChanger* changer, const char stagename[30]) : BaseScene(keyboard,sound,changer) {
	gamecanvas_ = (CanvasBase*) new GameUsually(keyboard_,this); 
	memcpy(stagename_, stagename, 30);
	stagemgr_ = (StageMgr*) new StageMgr(keyboard_,sound_,this,stagename_);
	nextstate_ = GameState::Game_None;
}

///<summary>
///<para>初期化処理</para>
///<para>字幕とステージの初期化処理を行う</para>
///</summary>
void Game::Initialize() {
	gamecanvas_->Initialize();
	stagemgr_->Initialize();
}

///<summary>
///<para>更新処理</para>
///<para>字幕の更新処理を行う</para>
///<para>nextstateが変更されていた場合、変更処理を行う</para>
///</summary>
void Game::Update() {
	UpdateNextState();
	if (typeid(*gamecanvas_) == typeid(GameUsually) || typeid(*gamecanvas_) == typeid(GameDance)) {
		stagemgr_->Update(); 
	}
	gamecanvas_->Update();
}

///<summary>
///<para>描写処理</para>
///<para>字幕とステージの描写処理を行う</para>
///</summary>
void Game::Draw() {
	stagemgr_->Draw();
	gamecanvas_->Draw();
}

///<summary>
///<para>終了処理</para>
///<para>字幕とステージの終了処理を行う</para>
///</summary>
void Game::Finalize() {
	BaseScene::Finalize();
	stagemgr_->Finalize();
}

///<summary>
///<para>ゲーム画面のBGMを再生する</para>
///</summary>
void Game::StartBgm() {
	sound_->PlayBgm(BGM_Name::BGM_Game);
}

///<summary>
///<para>nextstate_が変更されていた場合、nextstate_の値によって対応する処理を行う</para>
///</summary>
void Game::UpdateNextState(){
	if (nextstate_ != GameState::Game_None) {
		gamecanvas_->Finalize();
		switch (nextstate_) {
		case GameState::Game_Usually:
			gamecanvas_ = (CanvasBase*) new GameUsually(keyboard_,this);
			gamecanvas_->Initialize();
			break;
		case GameState::Game_Menu:
			gamecanvas_ = (CanvasBase*) new GameMenu(keyboard_, this);
			gamecanvas_->Initialize();
			break;
		case GameState::Game_Dance:
			gamecanvas_ = (CanvasBase*) new GameDance(keyboard_, this);
			gamecanvas_->Initialize();
			break;
		case GameState::Game_Clear:
			gamecanvas_ = (CanvasBase*) new GameClear(keyboard_, this);
			gamecanvas_->Initialize();
			break;
		case GameState::Game_Retry:
			stagemgr_->Retry();
			gamecanvas_ = (CanvasBase*) new GameUsually(keyboard_, this);
			gamecanvas_->Initialize();
			break;
		case GameState::Game_Exit:
			scenechanger_->ChangeScene(Scene::Scene_Title);
			break;
		default:
			assert(false);
			break;
		}
		nextstate_ = GameState::Game_None;
	}
}

///<summary>
///<para>Stateの変更処理</para>
///<para>nextstate_を引数の値に変更する</para>
///<param name= "state"><para>nextstate_にCopyする値</para></param>
///</summary>
void Game::ChangeState(GameState state) {
	this->nextstate_ = state;
}