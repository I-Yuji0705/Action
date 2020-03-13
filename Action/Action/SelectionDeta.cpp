#include "SelectionDeta.h"
#include "DxLib.h"

SelectionDeta::SelectionDeta(int x, int y, const char words[128], unsigned int color) {
	x_ = x;
	y_ = y;
	memcpy(words_ ,words,128);
	color_ = color;
}
void SelectionDeta::ChangeColor(unsigned int color) {
	color_ = color;
}
void SelectionDeta::Draw() {
	DrawString(x_, y_, words_, color_);
}