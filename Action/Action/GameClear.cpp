#include "GameClear.h"
#include "DxLib.h"
#include <iostream>
#include "SelectionDeta.h"

GameClear::GameClear(Keyboard* keyboard,IGameStateChanger* statechanger) : GameSelectionBase(keyboard,statechanger) {
	drawingdeta_.push_back((DrawingDeta*)new SelectionDeta(250, 100, "ゲームクリア！", GetColor(0, 0, 0)));
}
//ゲームクリア時の初期化処理
void GameClear::Initialize() {
	SelectionBase::Initialize();
}
//ゲームクリア時の更新処理
void GameClear::Update() {
	if (keyboard_->CheckKey(KEY_INPUT_RETURN) == 1 ||
		keyboard_->CheckKey(KEY_INPUT_ESCAPE) == 1) {
		statechanger_->ChangeState(Game_Exit);//シーンをメニューに変更
	}
}