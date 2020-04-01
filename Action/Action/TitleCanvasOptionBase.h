#pragma once
#include "BaseScene.h"
#include "ITitleStateChanger.h"
#include "CanvasOptionBase.h"

//TitleScene���ł̑I������S��������N���X
class TitleCanvasOptionBase : public CanvasOptionBase {
protected:
	ITitleStateChanger* statechanger_;
public:
	TitleCanvasOptionBase(Keyboard* keyboard, ITitleStateChanger* statechanger);
};
