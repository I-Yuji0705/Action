#pragma once
#include "MenuSelectionBase.h"

//Menu���ōŏ��ɕ\��������N���X
class MenuUsually : public MenuSelectionBase {
public:
	MenuUsually(IMenuStateChanger* statechanger);
	void Initialize() final;
	void Update() final;
};