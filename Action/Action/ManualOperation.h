#pragma once
#include "ManualSelectionBase.h"

//�}�j���A�����ő�����@��\��������N���X
class ManualOperation : public ManualSelectionBase {
public:
	ManualOperation(IManualStateChanger* statechanger);
	void Initialize() final;
};