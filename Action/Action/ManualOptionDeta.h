#pragma once
#include "OptionDetaBase.h"
#include "IManualStateChanger.h"

//�}�j���A�����őI������\������\�����钊�ۃN���X
class ManualOptionDeta : public OptionDetaBase {
private:
	IManualStateChanger* statechanger_;
	ManualState changestate_;
public:
	ManualOptionDeta(int x, int y, const char word[128], unsigned int color, IManualStateChanger* statechanger, ManualState state);
	void Opt() override;
};
