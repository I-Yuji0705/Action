#pragma once
#include "DrawingDeta.h"
//���ڂ�\������N���X
class TextDeta : public DrawingDeta{
protected:
	int x_;
	int y_; 
	char words_[128];
	unsigned int color_;
public:
	TextDeta(int x, int y,const char word[128], unsigned int color);
	void Draw()override;//�`�ʏ���
};