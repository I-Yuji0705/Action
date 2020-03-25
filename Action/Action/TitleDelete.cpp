#include "TitleDelete.h"
#include "DxLib.h"
#include "Keyboard.h"
#include <assert.h>
#include "TextDeta.h"
#include "TitleOptionDeta.h"

///<summary>
///<para>�R���X�g���N�^</para>
///<para>�Q�[���̏I���m�F���鎚���̐���</para>
///</summary>
TitleDelete::TitleDelete(Keyboard* keyboard, ITitleStateChanger* statechanger) :TitleCanvasOptionBase(keyboard,statechanger){
	optiondeta_.push_back((OptionDetaBase*)new TitleOptionDeta(300, 350, "�͂�", GetColor(0, 0, 0),statechanger, Title_Exit));
	optiondeta_.push_back((OptionDetaBase*)new TitleOptionDeta(300, 400, "������", GetColor(0, 0, 0),statechanger, Title_Usually));
	drawingdeta_.push_back((DrawingDeta*)new TextDeta(200, 300, "�{���ɃQ�[�����I�����܂����H", GetColor(0, 0, 0)));
}