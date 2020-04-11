#pragma once
#include "DrawingData.h"
//€–Ú‚ğ•\¦‚·‚éƒNƒ‰ƒX
class TextData : public DrawingData{
protected:
	int x_;
	int y_; 
	char words_[128];
	unsigned int color_;
public:
	TextData(int x, int y,const char word[128], unsigned int color);
	void Draw()override;//•`Êˆ—
};