#pragma once
#include "BaseScene.h"
#include "IManualStateChanger.h"
#include "SelectionBase.h"

//ManualScene���ł̍��ڂ̒��ۃN���X
class ManualSelectionBase : public SelectionBase {
protected:
	IManualStateChanger* statechanger_;
public:
	ManualSelectionBase(IManualStateChanger* statechanger);
	virtual void Update()override;
};