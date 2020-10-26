#include "GameClear.h"
#include "DxLib.h"
#include <iostream>
#include "TextData.h"

///<summary>
///<para>コンストラクタ</para>
///<para>ゲームクリア時の字幕の生成</para>
///</summary>
GameClear::GameClear(Keyboard* keyboard,IGameStateChanger* statechanger) : GameCanvasBase(keyboard,statechanger) {
	drawingData_.push_back((DrawingData*)new TextData(250, 100, "ゲームクリア！", GetColor(0, 0, 0)));
}

///<summary>
///<para>更新処理</para>
///<para>Enterキーか、Escapeキーがあった場合、タイトルシーンに移行する</para>
///</summary>
void GameClear::Update() {
	if (keyboard_->CheckKey(KEY_INPUT_RETURN) == 1 ||
		keyboard_->CheckKey(KEY_INPUT_ESCAPE) == 1) {
		statechanger_->ChangeState(GameState::Game_Exit);//シーンをタイトルに変更
	}
}