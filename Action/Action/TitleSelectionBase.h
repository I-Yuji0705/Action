#pragma once
#include "BaseScene.h"
#include "ITitleStateChanger.h"
#include "SelectionBase.h"

//MenuScene���ł̍��ڂ̊��N���X
class TitleSelectionBase : public SelectionBase {
protected:
	ITitleStateChanger* statechanger_;
public:
	TitleSelectionBase(Keyboard* keyboard, ITitleStateChanger* statechanger);
};