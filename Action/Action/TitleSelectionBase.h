#pragma once
#include "BaseScene.h"
#include "ITitleStateChanger.h"
#include "SelectionBase.h"

//MenuScene“à‚Å‚Ì€–Ú‚ÌŠî’êƒNƒ‰ƒX
class TitleSelectionBase : public SelectionBase {
protected:
	ITitleStateChanger* statechanger_;
public:
	TitleSelectionBase(Keyboard* keyboard, ITitleStateChanger* statechanger);
};