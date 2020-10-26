#include "ManualUsually.h"
#include "DxLib.h"
#include <assert.h>
#include "TextData.h"
#include "ManualOptionData.h"

///<summary>
///<para>�R���X�g���N�^</para>
///<para>�}�j���A�����ő��̃}�j���A����I�����鎚���̐���</para>
///</summary>
ManualUsually::ManualUsually(Keyboard* keyboard, IManualStateChanger* statechanger) :ManualCanvasOptionBase(keyboard,statechanger) {
	drawingData_.push_back((DrawingData*)new TextData(250, 100, "�}�j���A��", GetColor(0, 0, 0)));
	optionData_.push_back((OptionDataBase*)new ManualOptionData(130, 250, "�v���C���[�̑�����@", GetColor(0, 0, 0),statechanger, ManualState::Manual_Operation));
	optionData_.push_back((OptionDataBase*)new ManualOptionData(130, 300, "�X�e�[�W��̃I�u�W�F�N�g�ꗗ", GetColor(0, 0, 0), statechanger, ManualState::Manual_Stage));
	optionData_.push_back((OptionDataBase*)new ManualOptionData(130, 350, "�X�e�[�W�̃N���A����", GetColor(0, 0, 0), statechanger, ManualState::Manual_Rule));
	optionData_.push_back((OptionDataBase*)new ManualOptionData(130, 400, "���j���[�ɖ߂�", GetColor(0, 0, 0), statechanger, ManualState::Manual_Exit));
}