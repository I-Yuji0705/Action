#pragma once
#include "TextDeta.h"

//選択肢を担当する基底クラス
class OptionDetaBase : public TextDeta{
public:
	OptionDetaBase(int x, int y, const char word[128], unsigned int color);
	virtual void Opt() = 0; 
	void ChangeColor(ColorCode color);//色の変更
};