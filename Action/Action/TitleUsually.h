#pragma once
#include "TitleSelectionBase.h"

//Menu内で最初に表示する基底クラス
class TitleUsually : public TitleSelectionBase {
public:
	TitleUsually(Keyboard* keyboard, ITitleStateChanger* statechanger);
	void Initialize() final;
	void Update() final;
};