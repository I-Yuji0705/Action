#include "Game.h"
#include "DxLib.h"
#include "Keyboard.h"
#include "GameClear.h"
#include "GameUsually.h"
#include "GameMenu.h"
#include "GameDance.h"
#include <assert.h>
#include <typeinfo>


Game::Game(Keyboard* keyboard, Sound* sound,ISceneChanger* changer) : BaseScene(keyboard,sound,changer) {
	gameselection_ = (GameSelectionBase*) new GameUsually(keyboard_,this);
	stagemgr_ = (StageMgr*) new StageMgr(keyboard_,sound_,this);
}
//‰Šú‰»
void Game::Initialize() {
	gameselection_->Initialize();
	stagemgr_->Initialize();
}
//XV
void Game::Update() {
	UpdateNextState();
	if (typeid(*gameselection_) == typeid(GameUsually) || typeid(*gameselection_) == typeid(GameDance)) {
		stagemgr_->Update(); 
	}
	gameselection_->Update();
}
//•`‰æ
void Game::Draw() {
	stagemgr_->Draw();
	gameselection_->Draw();
}
//I—¹ˆ—
void Game::Finalize() {
	BaseScene::Finalize();
	stagemgr_->Finalize();
}
void Game::StartBgm() {
	sound_->PlayBgm(BGM_Game);
}

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
			scenechanger_->ChangeScene(Scene_Menu);
			break;
		default:
			assert(false);
			break;
		}
		nextstate_ = Game_None;
	}
}
void Game::ChangeState(GameState state) {
	this->nextstate_ = state;
}