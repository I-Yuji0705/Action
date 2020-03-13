#include "ManualUsually.h"
#include "DxLib.h"
#include "Keyboard.h"
#include <assert.h>
#include "SelectionDeta.h"

ManualUsually::ManualUsually(IManualStateChanger* statechanger) :ManualSelectionBase(statechanger) {
}

void ManualUsually::Initialize() {
	drawingdeta_.push_back((DrawingDeta*)new SelectionDeta(250, 100, "マニュアル", GetColor(0, 0, 0)));
	choicedeta_.push_back((DrawingDeta*)new SelectionDeta(130, 250, "プレイヤーの操作方法", GetColor(0, 0, 0)));
	choicedeta_.push_back((DrawingDeta*)new SelectionDeta(130, 300, "ステージ上のオブジェクト一覧", GetColor(0, 0, 0)));
	choicedeta_.push_back((DrawingDeta*)new SelectionDeta(130, 350, "ステージのクリア条件", GetColor(0, 0, 0)));
	choicedeta_.push_back((DrawingDeta*)new SelectionDeta(130, 400, "メニューに戻る", GetColor(0, 0, 0)));
	SelectionBase::Initialize();
}

void ManualUsually::Update() {
	SelectionBase::SelectSelection();
	SelectionBase::SelectionColorChange();
	//Enterキーを入力したとき
	if (Keyboard::getInstance()->CheckKey(KEY_INPUT_RETURN) == 1) {
		switch (selectnum_) {
		case 0:
			statechanger_->ChangeState(Manual_Operation);
			break;
		case 1:
			statechanger_->ChangeState(Manual_Stage);
			break;
		case 2:
			statechanger_->ChangeState(Manual_Rule);
			break;
		case 3:
			statechanger_->ChangeState(Manual_Exit);
			break;
		default:
			assert(false);
			break;
		}
	}
}