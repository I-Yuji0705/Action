#include "TitleUsually.h"
#include "DxLib.h"
#include "Keyboard.h"
#include <assert.h>
#include "TextData.h"
#include "TitleOptionData.h"

///<summary>
///<para>�R���X�g���N�^</para>
///<para>�����̐���</para>
///</summary>
TitleUsually::TitleUsually(Keyboard* keyboard, ITitleStateChanger* statechanger) :TitleCanvasOptionBase(keyboard,statechanger){
	optionData_.push_back((OptionDataBase*) new TitleOptionData(400, 300, "�Q�[���X�^�[�g", GetColor(0, 0, 0),statechanger, Title_Game));
	optionData_.push_back((OptionDataBase*) new TitleOptionData(400, 350, "�Q�[���I��", GetColor(0, 0, 0),statechanger, Title_Delete));
	optionData_.push_back((OptionDataBase*) new TitleOptionData(400, 400, "�������", GetColor(0, 0, 0), statechanger, Title_Intersection));
	drawingData_.push_back((DrawingData*) new TextData(130, 380, "Enter�L�[:���ڂ̌���", GetColor(0, 0, 0)));
	drawingData_.push_back((DrawingData*) new TextData(130, 400, "�㉺�L�[�F���ڂ̑I��", GetColor(0, 0, 0)));
}
