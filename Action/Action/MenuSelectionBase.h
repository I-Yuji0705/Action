#pragma once
#include "BaseScene.h"
#include "IMenuStateChanger.h"
#include "SelectionBase.h"

//MenuScene“à‚Å‚Ì€–Ú‚ÌŠî’êƒNƒ‰ƒX
class MenuSelectionBase : public SelectionBase {
protected:
	IMenuStateChanger* statechanger_;
public:
	MenuSelectionBase(Keyboard* keyboard, IMenuStateChanger* statechanger);
};