#include "Game.h"
#include "DxLib.h"
#include "Keyboard.h"

void Game::NormalUpdate() {
	if (Keyboard::getInstance()->CheckKey(KEY_INPUT_ESCAPE) == 1) { //Escキーが押されていたら
		state = Game_Menu;
	}
	stagemgr_->Update();
}
void Game::NormalDraw() {
	DrawString(10, 0, "Escキーを押すとメニュー画面に戻ります。", GetColor(0, 0, 0));
}
void Game::MenuInitialize() {
	selectMenuNum = 0;
	menuMessage_[0] = { 300,100,"つづける" };
	menuMessage_[1] = { 300,150,"でなおす" };
	menuMessage_[2] = { 300,200,"やりなおす" };
}
void Game::MenuUpdate() {
	if (Keyboard::getInstance()->CheckKey(KEY_INPUT_DOWN) == 1 ) {
		selectMenuNum = (selectMenuNum + 1) % 3;
	}
	else if (Keyboard::getInstance()->CheckKey(KEY_INPUT_UP) == 1) {
		selectMenuNum = (selectMenuNum + 2) % 3;
	}
	if (Keyboard::getInstance()->CheckKey(KEY_INPUT_RETURN) == 1) {
		switch (selectMenuNum) {
		case 0:
			state = Game_Normal;
			break;
		case 1:
			SceneChanger->ChangeScene(Scene_Menu);
			break;
		case 2:
			Retry();
			break;
		}
	}
}
void Game::MenuDraw() {
	for (int i = 0; i < 3; i++) {
		unsigned int selectColor;
		if (selectMenuNum == i) selectColor = GetColor(100, 100, 100);
		else selectColor = GetColor(200, 200, 200);
		DrawString(menuMessage_[i].x, menuMessage_[i].y, menuMessage_[i].name, selectColor);
	}
}
void Game::RetryInitialize() {
	selectRetryNum = 0;
	retryMessage_[0] = { 300, 100, "つづける" };
	retryMessage_[1] = { 300, 150,"でなおす" };
}
void Game::RetryUpdate() {
	if (Keyboard::getInstance()->CheckKey(KEY_INPUT_DOWN) == 1 ||
		Keyboard::getInstance()->CheckKey(KEY_INPUT_UP) == 1) {
		selectRetryNum = (selectRetryNum + 1) % 2;
	}
	if (Keyboard::getInstance()->CheckKey(KEY_INPUT_RETURN) == 1) {
		switch (selectRetryNum) {
		case 0:
			Retry();
			break;
		case 1:
			SceneChanger->ChangeScene(Scene_Menu);
			break;
		}
	}
}
void Game::RetryDraw() {
	for (int i = 0; i < 2; i++) {
		unsigned int selectColor;
		if (selectRetryNum == i) selectColor = GetColor(100, 100, 100);
		else selectColor = GetColor(200, 200, 200);
		DrawString(retryMessage_[i].x, retryMessage_[i].y, retryMessage_[i].name, selectColor);
	}
}
void Game::Retry() {
	stagemgr_->Retry();
	state = Game_Normal;
	Update();
}
void Game::ClearUpdate() {
	if (Keyboard::getInstance()->CheckKey(KEY_INPUT_RETURN) == 1 ||
		Keyboard::getInstance()->CheckKey(KEY_INPUT_ESCAPE) == 1) {
		SceneChanger->ChangeScene(Scene_Menu);//シーンをメニューに変更
	}
}
void Game::ClearDraw() {
	DrawString(200, 100, "ゲームクリア！", GetColor(0, 0, 0));
}


Game::Game(ISceneChanger* changer) : BaseScene(changer) {
}
//初期化
void Game::Initialize() {
	state = Game_Normal;
	stagemgr_ = new StageMgr();
	stagemgr_->Initialize(this);
	RetryInitialize();
	MenuInitialize();
}
//更新
void Game::Update() {
	switch (state) {
	case Game_Normal:
		NormalUpdate();
		break;
	case Game_Retry:
		RetryUpdate();
		break;
	case Game_Clear:
		ClearUpdate();
		break;
	case Game_Menu:
		MenuUpdate();
		break;
	default:
		break;
	}
}
//描画
void Game::Draw() {
	stagemgr_->Draw();
	switch (state) {
	case Game_Normal:
		NormalDraw();
		break;
	case Game_Menu:
		MenuDraw();
		break;
	case Game_Clear:
		ClearDraw();
		break;
	case Game_Retry:
		RetryDraw();
		break;
	default:
		break;
	};
}
void Game::Finalize() {
	BaseScene::Finalize();
	
	stagemgr_->Finalize();
}
void Game::ChangeState(State state) {
	this->state = state;
}