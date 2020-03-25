#pragma once
#include "BaseScene.h"
#include "IManualStateChanger.h"
#include "CanvasBase.h"

//ManualScene“à‚Å‚Ì€–Ú‚Ì’ŠÛƒNƒ‰ƒX
class ManualCanvasBase : public CanvasBase {
protected:
	IManualStateChanger* statechanger_;
public:
	ManualCanvasBase(Keyboard* keyboard,IManualStateChanger* statechanger);
	virtual void Update()override;
};