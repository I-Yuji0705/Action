#include "ManualUsually.h"
#include "DxLib.h"
#include <assert.h>
#include "SelectionDeta.h"

///<summary>
///<para>�R���X�g���N�^</para>
///<para>�}�j���A�����ő��̃}�j���A����I�����鎚���̐���</para>
///</summary>
ManualUsually::ManualUsually(Keyboard* keyboard, IManualStateChanger* statechanger) :ManualSelectionBase(keyboard,statechanger) {
	drawingdeta_.push_back((DrawingDeta*)new SelectionDeta(250, 100, "�}�j���A��", GetColor(0, 0, 0)));
	choicedeta_.push_back((DrawingDeta*)new SelectionDeta(130, 250, "�v���C���[�̑�����@", GetColor(0, 0, 0)));
	choicedeta_.push_back((DrawingDeta*)new SelectionDeta(130, 300, "�X�e�[�W��̃I�u�W�F�N�g�ꗗ", GetColor(0, 0, 0)));
	choicedeta_.push_back((DrawingDeta*)new SelectionDeta(130, 350, "�X�e�[�W�̃N���A����", GetColor(0, 0, 0)));
	choicedeta_.push_back((DrawingDeta*)new SelectionDeta(130, 400, "���j���[�ɖ߂�", GetColor(0, 0, 0)));
}

///<summary>
///<para>����������</para>
///</summary>
void ManualUsually::Initialize() {
	SelectionBase::Initialize();
}

///<summary>
///<para>�X�V����</para>
///<para>�㉺�L�[����͂����ہA�I�����Ă��鍀�ڂ��㉺����</para>
///<para>Enter�L�[���������ہA�I�񂾑I��������ĈقȂ�State�ɕύX����</para>
///</summary>
void ManualUsually::Update() {
	SelectionBase::SelectSelection();
	SelectionBase::SelectionColorChange();
	//Enter�L�[����͂����Ƃ�
	if (keyboard_->CheckKey(KEY_INPUT_RETURN) == 1) {
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