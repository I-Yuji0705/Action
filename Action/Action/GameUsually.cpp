#include "GameUsually.h"
#include "DxLib.h"
#include "Keyboard.h"
#include <assert.h>
#include "SelectionDeta.h"

GameUsually::GameUsually(IGameStateChanger *statechanger) : GameSelectionBase(statechanger) {
}
void GameUsually::Initialize() {
	drawingdeta_.push_back((DrawingDeta*)new SelectionDeta(10, 0, "Escキーを押すとメニュー画面に戻ります。", GetColor(0, 0, 0)));
	SelectionBase::Initialize();

}
//通常時の更新処理
void GameUsually::Update() {
	if (Keyboard::getInstance()->CheckKey(KEY_INPUT_ESCAPE) == 1) { //Escキーが押されていたら
		statechanger_->ChangeState(Game_Menu);
	}
}