#include "GameClear.h"
#include "DxLib.h"
#include <iostream>
#include "SelectionDeta.h"

///<summary>
///<para>コンストラクタ</para>
///<para>ゲームクリア時の字幕の生成</para>
///</summary>
GameClear::GameClear(Keyboard* keyboard,IGameStateChanger* statechanger) : GameSelectionBase(keyboard,statechanger) {
	drawingdeta_.push_back((DrawingDeta*)new SelectionDeta(250, 100, "ゲームクリア！", GetColor(0, 0, 0)));
}

///<summary>
///<para>初期化処理</para>
///</summary>
void GameClear::Initialize() {
	SelectionBase::Initialize();
}

///<summary>
///<para>更新処理</para>
///<para>Enterキーか、Escapeキーがあった場合、メニューシーンに移行する</para>
///</summary>
void GameClear::Update() {
	if (keyboard_->CheckKey(KEY_INPUT_RETURN) == 1 ||
		keyboard_->CheckKey(KEY_INPUT_ESCAPE) == 1) {
		statechanger_->ChangeState(Game_Exit);//シーンをメニューに変更
	}
}