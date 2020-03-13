#pragma once
#include "BaseScene.h"
#include "ITitleStateChanger.h"
#include "SelectionBase.h"

//MenuScene内での項目の基底クラス
class TitleSelectionBase : public SelectionBase {
protected:
	ITitleStateChanger* statechanger_;
public:
	TitleSelectionBase(Keyboard* keyboard, ITitleStateChanger* statechanger);
};