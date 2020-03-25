#include "ManualUsually.h"
#include "DxLib.h"
#include <assert.h>
#include "TextDeta.h"
#include "ManualOptionDeta.h"

///<summary>
///<para>�R���X�g���N�^</para>
///<para>�}�j���A�����ő��̃}�j���A����I�����鎚���̐���</para>
///</summary>
ManualUsually::ManualUsually(Keyboard* keyboard, IManualStateChanger* statechanger) :ManualCanvasOptionBase(keyboard,statechanger) {
	drawingdeta_.push_back((DrawingDeta*)new TextDeta(250, 100, "�}�j���A��", GetColor(0, 0, 0)));
	optiondeta_.push_back((OptionDetaBase*)new ManualOptionDeta(130, 250, "�v���C���[�̑�����@", GetColor(0, 0, 0),statechanger, Manual_Operation));
	optiondeta_.push_back((OptionDetaBase*)new ManualOptionDeta(130, 300, "�X�e�[�W��̃I�u�W�F�N�g�ꗗ", GetColor(0, 0, 0), statechanger, Manual_Stage));
	optiondeta_.push_back((OptionDetaBase*)new ManualOptionDeta(130, 350, "�X�e�[�W�̃N���A����", GetColor(0, 0, 0), statechanger, Manual_Rule));
	optiondeta_.push_back((OptionDetaBase*)new ManualOptionDeta(130, 400, "���j���[�ɖ߂�", GetColor(0, 0, 0), statechanger, Manual_Exit));
}