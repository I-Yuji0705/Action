#pragma once
#include "ManualSelectionBase.h"

//�}�j���A�����őI�������瑼�̏�ԂɈڍs������N���X
class ManualUsually : public ManualSelectionBase {
public:
	ManualUsually(Keyboard* keyboard,IManualStateChanger* statechanger);
	void Initialize() final;
	void Update() final;
};