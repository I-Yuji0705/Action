#include "ManualStage.h"
#include "DxLib.h"
#include "GraphDeta.h"
#include "TextDeta.h"

///<summary>
///<para>�R���X�g���N�^</para>
///<para>�}�j���A�����̃X�e�[�W���̎����̐���</para>
///</summary>
ManualStage::ManualStage(Keyboard* keyboard, IManualStateChanger* statechanger) :ManualCanvasBase(keyboard,statechanger) {
	drawingdeta_.push_back((DrawingDeta*) new TextDeta(250, 100, "�X�e�[�W��̃I�u�W�F�N�g�ꗗ", GetColor(0, 0, 0)));
	drawingdeta_.push_back((DrawingDeta*) new GraphDeta(130, 120, 180, 170, LoadGraph("Image/Player_2.png")));
	drawingdeta_.push_back((DrawingDeta*) new TextDeta(190, 140, "�v���C���[:�v���C���[�����삷��L�����N�^�[�ł��B", GetColor(0, 0, 0)));
	drawingdeta_.push_back((DrawingDeta*) new GraphDeta(130, 220, 180, 270, LoadGraph("Image/Item.png")));
	drawingdeta_.push_back((DrawingDeta*) new TextDeta(190, 240, "�A�C�e���F", GetColor(0, 0, 0)));
	drawingdeta_.push_back((DrawingDeta*) new TextDeta(270, 240, "�v���C���[����������A�u������A", GetColor(0, 0, 0)));
	drawingdeta_.push_back((DrawingDeta*) new TextDeta(270, 260, "��������ł���I�u�W�F�N�g�ł��B", GetColor(0, 0, 0)));
	drawingdeta_.push_back((DrawingDeta*) new TextDeta(130, 340, "���Â��G���A�F", GetColor(0, 0, 0)));
	drawingdeta_.push_back((DrawingDeta*) new TextDeta(260, 340, "�ςݍ��݃G���A�ł��B", GetColor(0, 0, 0)));
	drawingdeta_.push_back((DrawingDeta*) new TextDeta(260, 360, "�ڂ����́u�X�e�[�W�̃N���A�����v�ɂāB", GetColor(0, 0, 0)));
}