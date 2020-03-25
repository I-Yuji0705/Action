#include "TitleUsually.h"
#include "DxLib.h"
#include "Keyboard.h"
#include <assert.h>
#include "TextDeta.h"
#include "TitleOptionDeta.h"

///<summary>
///<para>�R���X�g���N�^</para>
///<para>�����̐���</para>
///</summary>
TitleUsually::TitleUsually(Keyboard* keyboard, ITitleStateChanger* statechanger) :TitleCanvasOptionBase(keyboard,statechanger){
	optiondeta_.push_back((OptionDetaBase*) new TitleOptionDeta(400, 300, "�Q�[���X�^�[�g", GetColor(0, 0, 0),statechanger, Title_Game));
	optiondeta_.push_back((OptionDetaBase*) new TitleOptionDeta(400, 350, "�Q�[���I��", GetColor(0, 0, 0),statechanger, Title_Delete));
	optiondeta_.push_back((OptionDetaBase*) new TitleOptionDeta(400, 400, "�������", GetColor(0, 0, 0), statechanger, Title_Intersection));
	drawingdeta_.push_back((DrawingDeta*) new TextDeta(130, 380, "Enter�L�[:���ڂ̌���", GetColor(0, 0, 0)));
	drawingdeta_.push_back((DrawingDeta*) new TextDeta(130, 400, "�㉺�L�[�F���ڂ̑I��", GetColor(0, 0, 0)));
}
