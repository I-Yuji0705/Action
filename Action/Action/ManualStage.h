#pragma once
#include "ManualSelectionBase.h"

//�}�j���A�����ŃX�e�[�W���̏���\��������N���X
class ManualStage : public ManualSelectionBase {
public:
	ManualStage(IManualStateChanger* statechanger);
	void Initialize() final;
};