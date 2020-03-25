#pragma once
#include "BaseScene.h"
#include "IManualStateChanger.h"
#include "CanvasBase.h"

//ManualScene���ł̍��ڂ̒��ۃN���X
class ManualCanvasBase : public CanvasBase {
protected:
	IManualStateChanger* statechanger_;
public:
	ManualCanvasBase(Keyboard* keyboard,IManualStateChanger* statechanger);
	virtual void Update()override;
};