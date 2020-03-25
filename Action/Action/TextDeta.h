#pragma once
#include "DrawingDeta.h"
//項目を表示するクラス
class TextDeta : public DrawingDeta{
protected:
	int x_;
	int y_; 
	char words_[128];
	unsigned int color_;
public:
	TextDeta(int x, int y,const char word[128], unsigned int color);
	void Draw()override;//描写処理
};