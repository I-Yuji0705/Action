#include "GameUsually.h"
#include "DxLib.h"
#include <assert.h>
#include "SelectionDeta.h"

GameUsually::GameUsually(Keyboard* keyboard, IGameStateChanger *statechanger) : GameSelectionBase(keyboard,statechanger) {
	drawingdeta_.push_back((DrawingDeta*)new SelectionDeta(10, 0, "Escキーを押すとメニュー画面に戻ります。", GetColor(0, 0, 0)));
	drawingdeta_.push_back((DrawingDeta*) new SelectionDeta(10, 20, "左右キー:プレイヤーの左右移動", GetColor(0, 0, 0)));
	drawingdeta_.push_back((DrawingDeta*) new SelectionDeta(10, 40, "上キー:プレイヤーのジャンプ", GetColor(0, 0, 0)));
	drawingdeta_.push_back((DrawingDeta*) new SelectionDeta(10, 60, "下キー:持っているアイテムを置く", GetColor(0, 0, 0)));
	drawingdeta_.push_back((DrawingDeta*) new SelectionDeta(10, 80, "Ctrlキー:プレイヤーの向きの反転", GetColor(0, 0, 0)));
	drawingdeta_.push_back((DrawingDeta*) new SelectionDeta(10, 100, "Spaceキー:アイテムを持つ/持っているアイテムを投げる", GetColor(0, 0, 0)));
}
void GameUsually::Initialize() {
	SelectionBase::Initialize();
}
//通常時の更新処理
void GameUsually::Update() {
	if (keyboard_->CheckKey(KEY_INPUT_ESCAPE) == 1) { //Escキーが押されていたら
		statechanger_->ChangeState(Game_Menu);
	}
}