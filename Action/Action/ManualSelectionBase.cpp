#include "ManualSelectionBase.h"
#include "DxLib.h"

ManualSelectionBase::ManualSelectionBase(Keyboard* keyboard,IManualStateChanger* statechanger): SelectionBase(keyboard) {
	statechanger_ = statechanger;
}
void ManualSelectionBase::Update() {
	if (keyboard_->CheckKey(KEY_INPUT_RETURN) == 1 ||
		keyboard_->CheckKey(KEY_INPUT_ESCAPE) == 1) {
		statechanger_->ChangeState(Manual_Usually);//シーンをメニューに変更
	}
}