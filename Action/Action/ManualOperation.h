#pragma once
#include "ManualSelectionBase.h"

//�}�j���A�����ő�����@��\��������N���X
class ManualOperation : public ManualSelectionBase {
public:
	ManualOperation(Keyboard* keyboard, IManualStateChanger* statechanger);
	void Initialize() final;
};