#pragma once
#include "BaseScene.h"
#include "IMenuStateChanger.h"
#include "SelectionBase.h"

//MenuScene���ł̍��ڂ̊��N���X
class MenuSelectionBase : public SelectionBase {
protected:
	IMenuStateChanger* statechanger_;
public:
	MenuSelectionBase(Keyboard* keyboard, IMenuStateChanger* statechanger);
};