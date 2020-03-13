#include "TitleUsually.h"
#include "DxLib.h"
#include "Keyboard.h"
#include <assert.h>
#include "SelectionDeta.h"

TitleUsually::TitleUsually(Keyboard* keyboard, ITitleStateChanger* statechanger) :TitleSelectionBase(keyboard,statechanger){
	choicedeta_.push_back((DrawingDeta*) new SelectionDeta(400, 300, "�Q�[���X�^�[�g", GetColor(0, 0, 0)));
	choicedeta_.push_back((DrawingDeta*) new SelectionDeta(400, 350, "�Q�[���I��", GetColor(0, 0, 0)));
	choicedeta_.push_back((DrawingDeta*) new SelectionDeta(400, 400, "�������", GetColor(0, 0, 0)));
	drawingdeta_.push_back((DrawingDeta*) new SelectionDeta(130, 380, "Enter�L�[:���ڂ̌���", GetColor(0, 0, 0)));
	drawingdeta_.push_back((DrawingDeta*) new SelectionDeta(130, 400, "�㉺�L�[�F���ڂ̑I��", GetColor(0, 0, 0)));
}

void TitleUsually::Initialize(){
	SelectionBase::Initialize();
}

void TitleUsually::Update(){
	SelectionBase::SelectSelection();
	SelectionBase::SelectionColorChange();
	//Enter�L�[����͂����Ƃ�
	if (keyboard_->CheckKey(KEY_INPUT_RETURN) == 1) {
		switch (selectnum_) {
		case 0:
			statechanger_->ChangeState(Title_Game);
			break;
		case 1:
			statechanger_->ChangeState(Title_Delete);
			break;
		case 2:
			statechanger_->ChangeState(Title_Intersection);
			break;
		default:
			assert(false);
			break;
		}
	}
}