#pragma once
#include "TitleCanvasOptionBase.h"

//Menu内で最初に表示する基底クラス
class TitleStageSelect : public TitleCanvasOptionBase {
public:
	TitleStageSelect(Keyboard* keyboard, ITitleStateChanger* statechanger);
};