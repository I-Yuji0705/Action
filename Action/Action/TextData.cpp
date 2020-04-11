#include "TextData.h"
#include "DxLib.h"

///<summary>
///<para>�R���X�g���N�^</para>
///<para>���ڂ̍����X���W�AY���W�A���ڂ̓��e�A���ڂ̐F�������Ƃ��Ď擾����</para>
///<para>����:</para>
///<param name= "x"><para>���ڂ̍����X���W</para></param>
///<param name= "y"><para>���ڂ̍����X���W</para></param>
///<param name= "words"><para>���ڂ̓��e</para></param>
///<param name= "color"><para>���ڂ̐F</para></param>
///</summary>
TextData::TextData(int x, int y, const char words[128], unsigned int color) {
	x_ = x;
	y_ = y;
	memcpy(words_ ,words,128);
	color_ = color;
}

///<summary>
///<para>�`�ʏ���</para>
///</summary>
void TextData::Draw() {
	DrawString(x_, y_, words_, color_);
}