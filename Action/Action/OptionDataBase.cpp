#include "OptionDataBase.h"
#include "DxLib.h"

///<summary>
///<para>�R���X�g���N�^</para>
///</summary>
OptionDataBase::OptionDataBase(int x, int y, const char word[128], unsigned int color) :TextData(x, y, word, color) {
}

///<summary>
///<para>�F�̕ύX����</para>
///<para>�󂯎�����\���̂����ƂɁAcolor_�̒l��ύX����</para>
///<param name= "color"><para>���ڂ̎O���F�������\����</para></param>
///</summary>
void OptionDataBase::ChangeColor(ColorCode color) {
	color_ = GetColor(color.Red, color.Green, color.Blue);
}
