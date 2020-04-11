#include "ManualOperation.h"
#include "DxLib.h"
#include "TextData.h"

///<summary>
///<para>�R���X�g���N�^</para>
///<para>�}�j���A�����̑�����@�̎����̐���</para>
///</summary>
ManualOperation::ManualOperation(Keyboard* keyboard, IManualStateChanger* statechanger) : ManualCanvasBase(keyboard,statechanger) {
	drawingData_.push_back((DrawingData*) new TextData(250, 100, "������@", GetColor(0, 0, 0)));
	drawingData_.push_back((DrawingData*) new TextData(130, 220, "���E�L�[:�v���C���[�̍��E�ړ�", GetColor(0, 0, 0)));
	drawingData_.push_back((DrawingData*) new TextData(130, 240, "��L�[:�v���C���[�̃W�����v", GetColor(0, 0, 0)));
	drawingData_.push_back((DrawingData*) new TextData(130, 260, "���L�[:�����Ă���A�C�e����u��", GetColor(0, 0, 0)));
	drawingData_.push_back((DrawingData*) new TextData(130, 280, "Ctrl�L�[:�v���C���[�̌����̔��]", GetColor(0, 0, 0)));
	drawingData_.push_back((DrawingData*) new TextData(130, 300, "Space�L�[:�A�C�e��������/�����Ă���A�C�e���𓊂���", GetColor(0, 0, 0)));
}