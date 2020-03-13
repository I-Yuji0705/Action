#include "ManualStage.h"
#include "DxLib.h"
#include "GraphDeta.h"
#include "SelectionDeta.h"

ManualStage::ManualStage(IManualStateChanger* statechanger) :ManualSelectionBase(statechanger) {
}

void ManualStage::Initialize() {
	drawingdeta_.push_back((DrawingDeta*) new SelectionDeta(250, 100, "�X�e�[�W��̃I�u�W�F�N�g�ꗗ", GetColor(0, 0, 0)));
	drawingdeta_.push_back((DrawingDeta*) new GraphDeta(130, 120,180,170, LoadGraph("Image/Player_2.png")));
	drawingdeta_.push_back((DrawingDeta*) new SelectionDeta(190, 140, "�v���C���[:�v���C���[�����삷��L�����N�^�[�ł��B", GetColor(0, 0, 0)));
	drawingdeta_.push_back((DrawingDeta*) new GraphDeta(130, 220, 180, 270, LoadGraph("Image/Item.png")));
	drawingdeta_.push_back((DrawingDeta*) new SelectionDeta(190, 240, "�A�C�e���F", GetColor(0, 0, 0)));
	drawingdeta_.push_back((DrawingDeta*) new SelectionDeta(270, 240, "�v���C���[����������A�u������A", GetColor(0, 0, 0)));
	drawingdeta_.push_back((DrawingDeta*) new SelectionDeta(270, 260, "��������ł���I�u�W�F�N�g�ł��B", GetColor(0, 0, 0)));
	drawingdeta_.push_back((DrawingDeta*) new SelectionDeta(130, 340, "���Â��G���A�F", GetColor(0, 0, 0)));
	drawingdeta_.push_back((DrawingDeta*) new SelectionDeta(260, 340, "�ςݍ��݃G���A�ł��B", GetColor(0, 0, 0)));
	drawingdeta_.push_back((DrawingDeta*) new SelectionDeta(260, 360, "�ڂ����́u�X�e�[�W�̃N���A�����v�ɂāB", GetColor(0, 0, 0)));
	SelectionBase::Initialize();
}