#pragma once
#include "BaseScene.h"
#include "IManualStateChanger.h"
#include "SelectionBase.h"

//ManualScene“à‚Å‚Ì€–Ú‚Ì’ŠÛƒNƒ‰ƒX
class ManualSelectionBase : public SelectionBase {
protected:
	IManualStateChanger* statechanger_;
public:
	ManualSelectionBase(IManualStateChanger* statechanger);
	virtual void Update()override;
};