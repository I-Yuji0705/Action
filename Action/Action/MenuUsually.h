#pragma once
#include "MenuSelectionBase.h"

//Menu“à‚ÅÅ‰‚É•\¦‚·‚éŠî’êƒNƒ‰ƒX
class MenuUsually : public MenuSelectionBase {
public:
	MenuUsually(Keyboard* keyboard, IMenuStateChanger* statechanger);
	void Initialize() final;
	void Update() final;
};