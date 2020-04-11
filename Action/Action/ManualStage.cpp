#include "ManualStage.h"
#include "DxLib.h"
#include "GraphData.h"
#include "TextData.h"

///<summary>
///<para>�R���X�g���N�^</para>
///<para>�}�j���A�����̃X�e�[�W���̎����̐���</para>
///</summary>
ManualStage::ManualStage(Keyboard* keyboard, IManualStateChanger* statechanger) :ManualCanvasBase(keyboard,statechanger) {
	drawingData_.push_back((DrawingData*) new TextData(250, 100, "�X�e�[�W��̃I�u�W�F�N�g�ꗗ", GetColor(0, 0, 0)));
	drawingData_.push_back((DrawingData*) new GraphData(130, 120, 180, 170, LoadGraph("Image/Player_2.png")));
	drawingData_.push_back((DrawingData*) new TextData(190, 140, "�v���C���[:�v���C���[�����삷��L�����N�^�[�ł��B", GetColor(0, 0, 0)));
	drawingData_.push_back((DrawingData*) new GraphData(130, 220, 180, 270, LoadGraph("Image/Item.png")));
	drawingData_.push_back((DrawingData*) new TextData(190, 240, "�A�C�e���F", GetColor(0, 0, 0)));
	drawingData_.push_back((DrawingData*) new TextData(270, 240, "�v���C���[����������A�u������A", GetColor(0, 0, 0)));
	drawingData_.push_back((DrawingData*) new TextData(270, 260, "��������ł���I�u�W�F�N�g�ł��B", GetColor(0, 0, 0)));
	drawingData_.push_back((DrawingData*) new TextData(130, 340, "���Â��G���A�F", GetColor(0, 0, 0)));
	drawingData_.push_back((DrawingData*) new TextData(260, 340, "�ςݍ��݃G���A�ł��B", GetColor(0, 0, 0)));
	drawingData_.push_back((DrawingData*) new TextData(260, 360, "�ڂ����́u�X�e�[�W�̃N���A�����v�ɂāB", GetColor(0, 0, 0)));
}