#pragma once
#include "TextDeta.h"

class OptionDetaBase : public TextDeta{
public:
	OptionDetaBase(int x, int y, const char word[128], unsigned int color);
	virtual void Opt() = 0; 
	void ChangeColor(ColorCode color);//F‚Ì•ÏX
};