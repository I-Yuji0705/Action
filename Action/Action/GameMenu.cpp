#include "GameMenu.h"
#include "DxLib.h"
#include <assert.h>
#include "SelectionDeta.h"

///<summary>
///<para>コンストラクタ</para>
///<para>ゲーム時のメニュー画面の生成</para>
///</summary>
GameMenu::GameMenu(Keyboard* keyboard,IGameStateChanger* statechanger)  : GameSelectionBase(keyboard,statechanger){
	choicedeta_.push_back((DrawingDeta*)new SelectionDeta(300, 100, "つづける", GetColor(0, 0, 0)));
	choicedeta_.push_back((DrawingDeta*)new SelectionDeta(300, 150, "でなおす", GetColor(0, 0, 0)));
	choicedeta_.push_back((DrawingDeta*)new SelectionDeta(300, 200, "やりなおす", GetColor(0, 0, 0)));
}

///<summary>
///<para>初期化設定</para>
///<para>ゲーム時のメニュー画面の生成</para>
///</summary>
void GameMenu::Initialize() {
	SelectionBase::Initialize();
}

///<summary>
///<para>更新処理</para>
///<para>Enterキーを押した際、選んだ選択肢よって異なるStateに変更する</para>
///</summary>
void GameMenu::Update() {
	SelectionBase::SelectSelection();
	SelectionBase::SelectionColorChange();
	if (keyboard_->CheckKey(KEY_INPUT_RETURN) == 1) {
		switch (selectnum_) {
		case 0:
			statechanger_->ChangeState(Game_Usually);
			break;
		case 1:
			statechanger_->ChangeState(Game_Exit);
			break;
		case 2:
			statechanger_->ChangeState(Game_Retry);
			break;
		default:
			assert(false);
			break;
		}
	}
}