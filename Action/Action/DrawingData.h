#pragma once
#include "ColorCode.h"

//���ڂ�摜��\�����钊�ۃN���X
class DrawingData {
public:
	virtual void Draw() = 0;
	virtual void Finalize() {};
};