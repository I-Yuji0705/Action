#pragma once
#include "BaseScene.h"
#include "IManualStateChanger.h"
#include "CanvasOptionBase.h"

//ManualScene���ł̍��ڂ̒��ۃN���X
class ManualCanvasOptionBase : public CanvasOptionBase {
protected:
	IManualStateChanger* statechanger_;
public:
	ManualCanvasOptionBase(Keyboard* keyboard, IManualStateChanger* statechanger);
};
