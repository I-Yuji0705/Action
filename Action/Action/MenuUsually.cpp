#include "MenuUsually.h"
#include "DxLib.h"
#include "Keyboard.h"
#include <assert.h>
#include "SelectionDeta.h"

MenuUsually::MenuUsually(IMenuStateChanger* statechanger) :MenuSelectionBase(statechanger){
}

void MenuUsually::Initialize(){
	choicedeta_.push_back((DrawingDeta*) new SelectionDeta(400, 300, "ゲームスタート", GetColor(0, 0, 0)));
	choicedeta_.push_back((DrawingDeta*) new SelectionDeta(400, 350, "ゲーム終了", GetColor(0, 0, 0)));
	choicedeta_.push_back((DrawingDeta*) new SelectionDeta(400, 400, "操作説明", GetColor(0, 0, 0)));
	drawingdeta_.push_back((DrawingDeta*) new SelectionDeta(130, 380, "Enterキー:項目の決定", GetColor(0, 0, 0)));
	drawingdeta_.push_back((DrawingDeta*) new SelectionDeta(130, 400, "上下キー：項目の選択", GetColor(0, 0, 0)));
	SelectionBase::Initialize();
}

void MenuUsually::Update(){
	SelectionBase::SelectSelection();
	SelectionBase::SelectionColorChange();
	//Enterキーを入力したとき
	if (Keyboard::getInstance()->CheckKey(KEY_INPUT_RETURN) == 1) {
		switch (selectnum_) {
		case 0:
			statechanger_->ChangeState(Menu_Game);
			break;
		case 1:
			statechanger_->ChangeState(Menu_Delete);
			break;
		case 2:
			statechanger_->ChangeState(Menu_Intersection);
			break;
		default:
			assert(false);
			break;
		}
	}
}
