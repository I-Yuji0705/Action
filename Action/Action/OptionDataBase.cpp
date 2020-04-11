#include "OptionDataBase.h"
#include "DxLib.h"

///<summary>
///<para>コンストラクタ</para>
///</summary>
OptionDataBase::OptionDataBase(int x, int y, const char word[128], unsigned int color) :TextData(x, y, word, color) {
}

///<summary>
///<para>色の変更処理</para>
///<para>受け取った構造体をもとに、color_の値を変更する</para>
///<param name= "color"><para>項目の三原色を示す構造体</para></param>
///</summary>
void OptionDataBase::ChangeColor(ColorCode color) {
	color_ = GetColor(color.Red, color.Green, color.Blue);
}
