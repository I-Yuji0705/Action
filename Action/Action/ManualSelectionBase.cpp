#include "ManualSelectionBase.h"
#include "Keyboard.h"
#include "DxLib.h"

ManualSelectionBase::ManualSelectionBase(IManualStateChanger* statechanger) {
	statechanger_ = statechanger;
}
void ManualSelectionBase::Update() {
	if (Keyboard::getInstance()->CheckKey(KEY_INPUT_RETURN) == 1 ||
		Keyboard::getInstance()->CheckKey(KEY_INPUT_ESCAPE) == 1) {
		statechanger_->ChangeState(Manual_Usually);//シーンをメニューに変更
	}
}