#pragma once
#include "TextData.h"

//�I������S��������N���X
class OptionDataBase : public TextData{
public:
	OptionDataBase(int x, int y, const char word[128], unsigned int color);
	virtual void Opt() = 0; 
	void ChangeColor(ColorCode color);//�F�̕ύX
};