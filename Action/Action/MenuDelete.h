#pragma once
#include "MenuSelectionBase.h"

//Menu���̃Q�[���I�����̑I������S��������N���X
class MenuDelete : public MenuSelectionBase {
public:
	MenuDelete(IMenuStateChanger* statechanger);
	void Initialize() final;
	void Update() final;
};