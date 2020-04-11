#include "GameUsually.h"
#include "DxLib.h"
#include <assert.h>
#include "TextData.h"

///<summary>
///<para>コンストラクタ</para>
///<para>ゲームの通常時に表示する字幕の生成</para>
///</summary>
GameUsually::GameUsually(Keyboard* keyboard, IGameStateChanger *statechanger) : GameCanvasBase(keyboard,statechanger) {
	drawingData_.push_back((DrawingData*)new TextData(10, 0, "Escキーを押すとメニュー画面に戻ります。", GetColor(0, 0, 0)));
	drawingData_.push_back((DrawingData*) new TextData(10, 20, "左右キー:プレイヤーの左右移動", GetColor(0, 0, 0)));
	drawingData_.push_back((DrawingData*) new TextData(10, 40, "上キー:プレイヤーのジャンプ", GetColor(0, 0, 0)));
	drawingData_.push_back((DrawingData*) new TextData(10, 60, "下キー:持っているアイテムを置く", GetColor(0, 0, 0)));
	drawingData_.push_back((DrawingData*) new TextData(10, 80, "Ctrlキー:プレイヤーの向きの反転", GetColor(0, 0, 0)));
	drawingData_.push_back((DrawingData*) new TextData(10, 100, "Spaceキー:アイテムを持つ/持っているアイテムを投げる", GetColor(0, 0, 0)));
}

///<summary>
///<para>更新処理</para>
///<para>Escapeキーを入力すると、ゲームメニューの表示を要請する</para>
///</summary>
void GameUsually::Update() {
	if (keyboard_->CheckKey(KEY_INPUT_ESCAPE) == 1) { //Escキーが押されていたら
		statechanger_->ChangeState(Game_Menu);
	}
}