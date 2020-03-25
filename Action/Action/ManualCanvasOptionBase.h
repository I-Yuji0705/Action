#pragma once
#include "BaseScene.h"
#include "IManualStateChanger.h"
#include "CanvasOptionBase.h"

//ManualScene“à‚Å‚Ì€–Ú‚Ì’ŠÛƒNƒ‰ƒX
class ManualCanvasOptionBase : public CanvasOptionBase {
protected:
	IManualStateChanger* statechanger_;
public:
	ManualCanvasOptionBase(Keyboard* keyboard, IManualStateChanger* statechanger);
};
