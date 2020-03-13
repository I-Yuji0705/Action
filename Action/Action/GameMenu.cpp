#include "GameMenu.h"
#include "DxLib.h"
#include "Keyboard.h"
#include <assert.h>
#include "SelectionDeta.h"
GameMenu::GameMenu(IGameStateChanger* statechanger)  : GameSelectionBase(statechanger){
}
//メニュー画面の初期化設定
void GameMenu::Initialize() {
	choicedeta_.push_back((DrawingDeta*)new SelectionDeta(300, 100, "つづける", GetColor(0, 0, 0)));
	choicedeta_.push_back((DrawingDeta*)new SelectionDeta(300, 150, "でなおす", GetColor(0, 0, 0)));
	choicedeta_.push_back((DrawingDeta*)new SelectionDeta(300, 200, "やりなおす", GetColor(0, 0, 0)));
	SelectionBase::Initialize();
}
//メニュー画面表示時のの更新処理
void GameMenu::Update() {
	SelectionBase::SelectSelection();
	SelectionBase::SelectionColorChange();
	if (Keyboard::getInstance()->CheckKey(KEY_INPUT_RETURN) == 1) {
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