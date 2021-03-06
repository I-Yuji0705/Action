#pragma once
#include "DrawingData.h"
//項目を表示するクラス
class TextData : public DrawingData{
protected:
	int x_;
	int y_; 
	char words_[128];
	unsigned int color_;
public:
	TextData(int x, int y,const char word[128], unsigned int color);
	void Draw()override;//描写処理
};