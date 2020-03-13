#include "MenuDelete.h"
#include "DxLib.h"
#include "Keyboard.h"
#include <assert.h>
#include "SelectionDeta.h"

MenuDelete::MenuDelete(IMenuStateChanger* statechanger) :MenuSelectionBase(statechanger){
}

void MenuDelete::Initialize(){
	choicedeta_.push_back((DrawingDeta*)new SelectionDeta(300, 350, "�͂�", GetColor(0, 0, 0))) ;
	choicedeta_.push_back((DrawingDeta*)new SelectionDeta(300, 400, "������", GetColor(0, 0, 0)));
	drawingdeta_.push_back((DrawingDeta*)new SelectionDeta(200, 300, "�{���ɃQ�[�����I�����܂����H", GetColor(0, 0, 0)));
	SelectionBase::Initialize();
}
void MenuDelete::Update(){
	SelectionBase::SelectSelection();
	SelectionBase::SelectionColorChange();
	//Enter�L�[����͂����Ƃ�
	if (Keyboard::getInstance()->CheckKey(KEY_INPUT_RETURN) == 1) {
		switch (selectnum_) {
		case 0:
			statechanger_->ChangeState(Menu_Exit);
			break;
		case 1:
			statechanger_->ChangeState(Menu_Usually);
			break;
		default:
			assert(false);
			break;
		}
	}
}