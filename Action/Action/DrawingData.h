#pragma once
#include "ColorCode.h"

//項目や画像を表示する抽象クラス
class DrawingData {
public:
	virtual void Draw() = 0;
	virtual void Finalize() {};
};