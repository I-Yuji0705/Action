#pragma once
#include "BaseScene.h"
#include "ITitleStateChanger.h"
#include "CanvasOptionBase.h"

//TitleScene���ł̍��ڂ̒��ۃN���X
class TitleCanvasOptionBase : public CanvasOptionBase {
protected:
	ITitleStateChanger* statechanger_;
public:
	TitleCanvasOptionBase(Keyboard* keyboard, ITitleStateChanger* statechanger);
};
