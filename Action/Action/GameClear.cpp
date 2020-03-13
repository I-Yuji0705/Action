#include "GameClear.h"
#include "DxLib.h"
#include <iostream>
#include "Keyboard.h"
#include "SelectionDeta.h"

GameClear::GameClear(IGameStateChanger* statechanger) : GameSelectionBase(statechanger) {
}
//ゲームクリア時の初期化処理
void GameClear::Initialize() {
	drawingdeta_.push_back((DrawingDeta*)new SelectionDeta(250, 100, "ゲームクリア！", GetColor(0, 0, 0)));
	SelectionBase::Initialize();
}
//ゲームクリア時の更新処理
void GameClear::Update() {
	if (Keyboard::getInstance()->CheckKey(KEY_INPUT_RETURN) == 1 ||
		Keyboard::getInstance()->CheckKey(KEY_INPUT_ESCAPE) == 1) {
		statechanger_->ChangeState(Game_Exit);//シーンをメニューに変更
	}
}