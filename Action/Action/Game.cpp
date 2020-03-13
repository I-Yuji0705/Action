#include "Game.h"
#include "DxLib.h"
#include <typeinfo.h>
Game::Game(ISceneChanger* changer) : BaseScene(changer) {
}
//初期化
void Game::Initialize() {
	state = Game_Normal;
	//player.Initialize(this, stage);
	item[0].Set(500.0f,340.0f,100.0f,100.0f,0);
	item[1].Set(1400.0f, 340.0f, 100.0f, 100.0f, 0);
	item[2].Set(1700.0f, 240.0f, 100.0f, 100.0f, 0);
	terrain[0].Set(0.0f, 440.0f,40.0f,800.0f,0);
	terrain[1].Set(400.0f, 240.0f, 100.0f, 200.0f, 0);
	terrain[2].Set(1200.0f, 440.0f, 40.0f, 800.0f,0);
	terrain[3].Set(1400.0f, 240.0f, 100.0f, 100.0f,0);
	terrain[4].Set(1700.0f, 340.0f, 100.0f, 100.0f, 0);
	terrain[5].Set(2100.0f, 440.0f, 100.0f, 800.0f,0);
	gate.Set(3000.0f, 340.0f, 100.0f, 100.0f,0);
	relaypoint[0].Set(800.0f,0.0f,1000.0f,10.0f,0);//1040
	player.Set(100.0f, 340.0f,100.0f,100.0f,0);//100
	stage[0] = &terrain[0];
	stage[1] = &terrain[1];
	stage[2] = &terrain[2];
	stage[3] = &terrain[3];
	stage[4] = &terrain[4];
	stage[5] = &terrain[5];
	stage[6] = &gate;
	stage[7] = &relaypoint[0];
	stage[8] = &item[0];
	stage[9] = &item[1];
	stage[10] = &item[2];
	stage[11] = &player;
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
		Normal();
		break;
	case Game_Retry:
		RetryUpdate();
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
	BaseScene::Draw();//親クラスの描画メソッドを呼ぶ
	DrawBox(0, 0, 640, 480, GetColor(200, 200, 255), TRUE);
	DrawString(0, 0, "Escキーを押すとメニュー画面に戻ります。", GetColor(255, 255, 255));
	for (int i = 0; i < stage[0]->object_num; i++) {
		stage[i]->Draw();
	}
	if(state == Game_Clear) DrawString(0, 80, "ゲームクリア！", GetColor(255, 255, 255));
	if (state == Game_Retry) RetryDraw();
}
void Game::Finalize() {
	BaseScene::Finalize();
	for (int i = 0; i < stage[0]->object_num; i++) {
		stage[i]->Finalize();
	}
	terrain[0].terrain_num =0;
	stage[0]->object_num = 0;
}
void Game::ChangeState(State state) {
	this->state = state;
}
void Game::ClearUpdate() {
	if (Keyboard::getInstance()->CheckKey(KEY_INPUT_RETURN) == 1 ||
		Keyboard::getInstance()->CheckKey(KEY_INPUT_ESCAPE) == 1) {
		SceneChanger->ChangeScene(Scene_Menu);//シーンをメニューに変更
	}
}
void Game::Normal() {
	if (Keyboard::getInstance()->CheckKey(KEY_INPUT_ESCAPE) == 1) { //Escキーが押されていたら
		SceneChanger->ChangeScene(Scene_Menu);//シーンをメニューに変更
	}
	for (int i = 0; i < stage[i]->object_num; i++) {
		stage[i]->Update();
	}
	//relaypoint[0].Update();
	//gate.Update();
	//item.Update();
	//player.Update();
	playerCamera.Update(stage, &player);
}
void Game::RetryUpdate() {
	if (Keyboard::getInstance()->CheckKey(KEY_INPUT_DOWN) == 1 ||
		Keyboard::getInstance()->CheckKey(KEY_INPUT_UP) == 1) {
		selectNum = (selectNum + 1) % 2;
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
void Game::Select() {
}
void Game::RetryInitialize() {
	selectNum = 0;
	retryMessage[0] = { 300,300,"つづける" };
	retryMessage[1] = { 300,350,"でなおす" };
}
void Game::Retry() {
	for (int i = 0; i < stage[i]->object_num; i++) {
		stage[i]->Retry();
	}
		state = Game_Normal;
		Update();
}
void Game::RetryDraw() {
	for (int i = 0; i < 2; i++) {
		unsigned int selectColor;
		if (selectNum == i) selectColor = GetColor(100, 100, 100);
		else selectColor = GetColor(255, 255, 255);
		DrawString(retryMessage[i].x, retryMessage[i].y, retryMessage[i].name, selectColor);
	}
}