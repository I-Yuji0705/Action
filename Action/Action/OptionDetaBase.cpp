#include "OptionDetaBase.h"
#include "DxLib.h"

///<summary>
///<para>�R���X�g���N�^</para>
///</summary>
OptionDetaBase::OptionDetaBase(int x, int y, const char word[128], unsigned int color) :TextDeta(x, y, word, color) {
}

///<summary>
///<para>�F�̕ύX����</para>
///<para>�󂯎�����\���̂����ƂɁAcolor_�̒l��ύX����</para>
///<para>����:</para>
///<param name= "color"><para>���ڂ̎O���F�������\����</para></param>
///</summary>
void OptionDetaBase::ChangeColor(ColorCode color) {
	color_ = GetColor(color.Red, color.Green, color.Blue);
}
