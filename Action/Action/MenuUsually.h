#pragma once
#include "MenuSelectionBase.h"

//Menu���ōŏ��ɕ\��������N���X
class MenuUsually : public MenuSelectionBase {
public:
	MenuUsually(Keyboard* keyboard, IMenuStateChanger* statechanger);
	void Initialize() final;
	void Update() final;
};