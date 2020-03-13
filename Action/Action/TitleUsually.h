#pragma once
#include "TitleSelectionBase.h"

//Menu“à‚ÅÅ‰‚É•\¦‚·‚éŠî’êƒNƒ‰ƒX
class TitleUsually : public TitleSelectionBase {
public:
	TitleUsually(Keyboard* keyboard, ITitleStateChanger* statechanger);
	void Initialize() final;
	void Update() final;
};