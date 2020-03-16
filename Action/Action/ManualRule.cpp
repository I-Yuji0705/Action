#include "ManualRule.h"
#include "DxLib.h"
#include "SelectionDeta.h"

///<summary>
///<para>�R���X�g���N�^</para>
///<para>�}�j���A�����̃N���A�����̎����̐���</para>
///</summary>
ManualRule::ManualRule(Keyboard* keyboard, IManualStateChanger* statechanger) :ManualSelectionBase(keyboard,statechanger) {
	drawingdeta_.push_back((DrawingDeta*) new SelectionDeta(250, 100, "�X�e�[�W�̃N���A����", GetColor(0, 0, 0)));
	drawingdeta_.push_back((DrawingDeta*) new SelectionDeta(130, 220, "�X�e�[�W���ɎU��΂�A�C�e�����W�߂āA", GetColor(0, 0, 0)));
	drawingdeta_.push_back((DrawingDeta*) new SelectionDeta(130, 240, "�X�e�[�W���ɂ���ςݏグ�G���A���I�u�W�F�N�g��", GetColor(0, 0, 0)));
	drawingdeta_.push_back((DrawingDeta*) new SelectionDeta(130, 260, "���ߐs�����ƃN���A���܂��B", GetColor(0, 0, 0)));
	drawingdeta_.push_back((DrawingDeta*) new SelectionDeta(130, 280, "�ςݏグ�G���A���ɖ��ߐs������I�u�W�F�N�g�́A", GetColor(0, 0, 0)));
	drawingdeta_.push_back((DrawingDeta*) new SelectionDeta(130, 300, "�ςݏグ�G���A�ȊO�̑S�Ă��Ώۂł��B", GetColor(0, 0, 0)));
	drawingdeta_.push_back((DrawingDeta*) new SelectionDeta(130, 320, "�܂�A�Ō�̈ꉟ���Ƀv���C���[���G���A�ɓ���", GetColor(0, 0, 0)));
	drawingdeta_.push_back((DrawingDeta*) new SelectionDeta(130, 340, "�Ă��N���A�ɂȂ�܂��B", GetColor(0, 0, 0)));
	drawingdeta_.push_back((DrawingDeta*) new SelectionDeta(130, 360, "�o���Ă����ƃN���A���y�ɂȂ邩������܂���B", GetColor(0, 0, 0)));
}

///<summary>
///<para>����������</para>
///</summary>
void ManualRule::Initialize() {
	SelectionBase::Initialize();
}