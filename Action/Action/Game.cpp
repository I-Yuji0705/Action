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
Game::Game(Keyboard* keyboard, Sound* sound,ISceneChanger* changer) : BaseScene(keyboard,sound,changer) {
	gameselection_ = (GameSelectionBase*) new GameUsually(keyboard_,this);
	stagemgr_ = (StageMgr*) new StageMgr(keyboard_,sound_,this);
}

///<summary>
///<para>初期化処理</para>
///<para>字幕とステージの初期化処理を行う</para>
///</summary>
void Game::Initialize() {
	gameselection_->Initialize();
	stagemgr_->Initialize();
}

///<summary>
///<para>更新処理</para>
///<para>現在のステートの変更要請の確認と、字幕とステージの更新処理を行う</para>
///</summary>
void Game::Update() {
	UpdateNextState();
	if (typeid(*gameselection_) == typeid(GameUsually) || typeid(*gameselection_) == typeid(GameDance)) {
		stagemgr_->Update(); 
	}
	gameselection_->Update();
}

///<summary>
///<para>描写処理</para>
///<para>字幕とステージの描写処理を行う</para>
///</summary>
void Game::Draw() {
	stagemgr_->Draw();
	gameselection_->Draw();
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
	sound_->PlayBgm(BGM_Game);
}

///<summary>
///<para>Stateの変更要請があった場合、変更処理を行う</para>
///</summary>
void Game::UpdateNextState(){
	if (nextstate_ != Game_None) {
		gameselection_->Finalize();
		switch (nextstate_) {
		case Game_Usually:
			gameselection_ = (GameSelectionBase*) new GameUsually(keyboard_,this);
			gameselection_->Initialize();
			break;
		case Game_Menu:
			gameselection_ = (GameSelectionBase*) new GameMenu(keyboard_, this);
			gameselection_->Initialize();
			break;
		case Game_Dance:
			gameselection_ = (GameSelectionBase*) new GameDance(keyboard_, this);
			gameselection_->Initialize();
			break;
		case Game_Clear:
			gameselection_ = (GameSelectionBase*) new GameClear(keyboard_, this);
			gameselection_->Initialize();
			break;
		case Game_Retry:
			stagemgr_->Retry();
			gameselection_ = (GameSelectionBase*) new GameUsually(keyboard_, this);
			gameselection_->Initialize();
			break;
		case Game_Exit:
			scenechanger_->ChangeScene(Scene_Title);
			break;
		default:
			assert(false);
			break;
		}
		nextstate_ = Game_None;
	}
}

///<summary>
///<para>Stateの変更要請</para>
///</summary>
void Game::ChangeState(GameState state) {
	this->nextstate_ = state;
}