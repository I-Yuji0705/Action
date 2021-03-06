#pragma once
#include "MenuSelectionBase.h"

//Menu内で最初に表示する基底クラス
class MenuUsually : public MenuSelectionBase {
public:
	MenuUsually(Keyboard* keyboard, IMenuStateChanger* statechanger);
	void Initialize() final;
	void Update() final;
};