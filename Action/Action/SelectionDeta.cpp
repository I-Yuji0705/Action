#include "SelectionDeta.h"
#include "DxLib.h"

///<summary>
///<para>コンストラクタ</para>
///<para>項目の左上のX座標、Y座標、項目の内容、項目の色を引数として取得する</para>
///<para>引数:</para>
///<param name= "x"><para>項目の左上のX座標</para></param>
///<param name= "y"><para>項目の左上のX座標</para></param>
///<param name= "words"><para>項目の内容</para></param>
///<param name= "color"><para>項目の色</para></param>
///</summary>
SelectionDeta::SelectionDeta(int x, int y, const char words[128], unsigned int color) {
	x_ = x;
	y_ = y;
	memcpy(words_ ,words,128);
	color_ = color;
}

///<summary>
///<para>色を変更処理</para>
///<para></para>
///<para>引数:</para>
///<param name= "color"><para>項目の三原色を示す構造体</para></param>
///</summary>
void SelectionDeta::ChangeColor(ColorCode color) {
	color_ = GetColor(color.Red,color.Green,color.Blue);
}
///<summary>
///<para>描写処理</para>
///</summary>
void SelectionDeta::Draw() {
	DrawString(x_, y_, words_, color_);
}