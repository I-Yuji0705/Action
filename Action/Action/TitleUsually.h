#pragma once
#include "TitleCanvasOptionBase.h"

//Menu内で最初に表示する基底クラス
class TitleUsually : public TitleCanvasOptionBase {
public:
	TitleUsually(Keyboard* keyboard, ITitleStateChanger* statechanger);
};