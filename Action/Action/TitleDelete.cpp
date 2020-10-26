#include "TitleDelete.h"
#include "DxLib.h"
#include "Keyboard.h"
#include <assert.h>
#include "TextData.h"
#include "TitleOptionData.h"

///<summary>
///<para>�R���X�g���N�^</para>
///<para>�Q�[���̏I���m�F���鎚���̐���</para>
///</summary>
TitleDelete::TitleDelete(Keyboard* keyboard, ITitleStateChanger* statechanger) :TitleCanvasOptionBase(keyboard,statechanger){
	optionData_.push_back((OptionDataBase*)new TitleOptionData(300, 350, "�͂�", GetColor(0, 0, 0),statechanger, TitleState::Title_Exit));
	optionData_.push_back((OptionDataBase*)new TitleOptionData(300, 400, "������", GetColor(0, 0, 0),statechanger, TitleState::Title_Usually));
	drawingData_.push_back((DrawingData*)new TextData(200, 300, "�{���ɃQ�[�����I�����܂����H", GetColor(0, 0, 0)));
}