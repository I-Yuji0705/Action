#pragma once
#include "BaseScene.h"
#include "IMenuStateChanger.h"
#include "SelectionBase.h"

//MenuScene内での項目の基底クラス
class MenuSelectionBase : public SelectionBase {
protected:
	IMenuStateChanger* statechanger_;
public:
	MenuSelectionBase(Keyboard* keyboard, IMenuStateChanger* statechanger);
};