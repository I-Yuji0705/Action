#include "Game.h"
#include <typeinfo.h>
#include "DxLib.h"
#include "Player.h"
#include "Terrain.h"
#include "Gate.h"
#include "Item.h"
#include "RelayPoint.h"

void Game::NormalUpdate() {
	if (Keyboard::getInstance()->CheckKey(KEY_INPUT_ESCAPE) == 1) { //Escキーが押されていたら
		SceneChanger->ChangeScene(Scene_Menu);//シーンをメニューに変更
	}
	for (int i = 0; i < stage[i]->object_num; i++) {
		stage[i]->Update();
	}
	playerCamera.Update(stage);
}
void Game::NormalDraw() {
	DrawString(10, 0, "Escキーを押すとメニュー画面に戻ります。", GetColor(0, 0, 0));
}
void Game::RetryInitialize() {
	selectNum = 0;
	retryMessage[0] = { 300,300,"つづける" };
	retryMessage[1] = { 300,350,"でなおす" };
}
void Game::RetryUpdate() {
	if (Keyboard::getInstance()->CheckKey(KEY_INPUT_DOWN) == 1 ||
		Keyboard::getInstance()->CheckKey(KEY_INPUT_UP) == 1) {
		selectNum = (selectNum + 1) % 2;
	}
	if (Keyboard::getInstance()->CheckKey(KEY_INPUT_ESCAPE) == 1) { 
		SceneChanger->ChangeScene(Scene_Menu);
	}
	if (Keyboard::getInstance()->CheckKey(KEY_INPUT_RETURN) == 1) {
		switch (selectNum) {
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
		if (selectNum == i) selectColor = GetColor(100, 100, 100);
		else selectColor = GetColor(200, 200, 200);
		DrawString(retryMessage[i].x, retryMessage[i].y, retryMessage[i].name, selectColor);
	}
}
void Game::Retry() {
	for (int i = 0; i < stage[i]->object_num; i++) {
		stage[i]->Retry();
	}
		state = Game_Normal;
		Update();
}
void Game::DanceUpdate() {
	//if (Keyboard::getInstance()->CheckKey(KEY_INPUT_RETURN) == 1 ||
	//	Keyboard::getInstance()->CheckKey(KEY_INPUT_ESCAPE) == 1) {
	//	SceneChanger->ChangeScene(Scene_Menu);//シーンをメニューに変更
	//}
	for (int i = 0; i < stage[i]->object_num; i++) {
		stage[i]->Update();
	}
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
	stage[0] = new Terrain();
	stage[1] = new Terrain();
	stage[2] = new Terrain();
	stage[3] = new Terrain();
	stage[4] = new Terrain();
	stage[5] = new Terrain();
	stage[6] = new Terrain();
	stage[7] = new Gate();
	stage[8] = new RelayPoint();
	stage[9] = new RelayPoint();
	stage[10] = new Item();
	stage[11] = new Item();
	stage[12] = new Item();
	stage[13] = new Player(); 
	
	stage[0]->Set(0.0f, 440.0f,40.0f,800.0f,0);
	stage[1]->Set(400.0f, 240.0f, 100.0f, 200.0f, 0);
	stage[2]->Set(1200.0f, 440.0f, 40.0f, 800.0f,0);
	stage[3]->Set(1400.0f, 240.0f, 100.0f, 100.0f,0);
	stage[4]->Set(1700.0f, 340.0f, 100.0f, 100.0f, 0);
	stage[5]->Set(2100.0f, 440.0f, 100.0f, 700.0f,0);
	stage[6]->Set(2800.0f, 240.0f,300.0f,300.0f,0);
	stage[7]->Set(2900.0f, 140.0f, 100.0f, 100.0f,0);
	stage[8]->Set(1200.0f,0.0f,1000.0f,10.0f,0);//1040
	stage[9]->Set(2100.0f, 0.0f, 1000.0f, 10.0f, 0);//1040
	stage[10]->Set(500.0f, 340.0f, 100.0f, 100.0f, 0);
	stage[11]->Set(1400.0f, 340.0f, 100.0f, 100.0f, 0);
	stage[12]->Set(1700.0f, 240.0f, 100.0f, 100.0f, 0);
	stage[13]->Set(100.0f, 340.0f,100.0f,100.0f,0);//100
	for (int i = 0; i < stage[0]->object_num; i++) {
		stage[i]->Initialize(this,stage);
	}
	playerCamera.Initialize(stage);
	RetryInitialize();
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
	case Game_Dance:
		DanceUpdate();
		break;
	case Game_Clear:
		ClearUpdate();
		break;
	default:
		break;
	}
}
//描画
void Game::Draw() {
	DrawBox(0, 0, 640, 480, GetColor(255, 255, 255), TRUE);
	for (int i = 0; i < stage[0]->object_num; i++) {
		stage[i]->Draw();
	}
	switch (state) {
	case Game_Normal:
		NormalDraw();
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
	for (int i = 0; i < stage[0]->object_num; i++) {
		stage[i]->Finalize();
	}
	stage[0]->object_num = 0;
}
void Game::ChangeState(State state) {
	this->state = state;
}