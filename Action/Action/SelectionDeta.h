#pragma once
#include "DrawingDeta.h"
//���ڂ�\������N���X
class SelectionDeta : public DrawingDeta{
	int x_;
	int y_; 
	char words_[128];
	unsigned int color_;
public:
	SelectionDeta(int x, int y,const char word[128], unsigned int color);
	void Draw()override;//�`�ʏ���
	void ChangeColor(ColorCode color)override;//�F�̕ύX
};