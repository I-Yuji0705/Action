#pragma once
#include "MenuSelectionBase.h"

//MenuΰΜQ[IΉΜIππS·ιξκNX
class MenuDelete : public MenuSelectionBase {
public:
	MenuDelete(Keyboard* keyboard, IMenuStateChanger* statechanger);
	void Initialize() final;
	void Update() final;
};