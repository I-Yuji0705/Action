#pragma once
#include "ManualSelectionBase.h"

//�}�j���A�����ŃQ�[���̃N���A������\��������N���X
class ManualRule : public ManualSelectionBase {
public:
	ManualRule(Keyboard* keyboard, IManualStateChanger* statechanger);
	void Initialize()final;
};