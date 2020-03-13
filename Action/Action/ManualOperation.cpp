#include "ManualOperation.h"
#include "DxLib.h"
#include "SelectionDeta.h"

ManualOperation::ManualOperation(IManualStateChanger* statechanger) :ManualSelectionBase(statechanger) {
}

void ManualOperation::Initialize() {
	drawingdeta_.push_back((DrawingDeta*) new SelectionDeta(250, 100, "������@", GetColor(0, 0, 0)));
	drawingdeta_.push_back((DrawingDeta*) new SelectionDeta(130, 220, "���E�L�[:�v���C���[�̍��E�ړ�", GetColor(0, 0, 0)));
	drawingdeta_.push_back((DrawingDeta*) new SelectionDeta(130, 240, "��L�[:�v���C���[�̃W�����v", GetColor(0, 0, 0)));
	drawingdeta_.push_back((DrawingDeta*) new SelectionDeta(130, 260, "���L�[:�����Ă���A�C�e����u��", GetColor(0, 0, 0)));
	drawingdeta_.push_back((DrawingDeta*) new SelectionDeta(130, 280, "Ctrl�L�[:�v���C���[�̌����̔��]", GetColor(0, 0, 0)));
	drawingdeta_.push_back((DrawingDeta*) new SelectionDeta(130, 300, "Space�L�[:�A�C�e��������/�����Ă���A�C�e���𓊂���", GetColor(0, 0, 0)));
	SelectionBase::Initialize();
}