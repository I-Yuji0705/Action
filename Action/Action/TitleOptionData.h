#pragma once
#include "OptionDataBase.h"
#include "ITitleStateChanger.h"

class ITitleStateChanger;
class TitleOptionData : public OptionDataBase {
protected:
	ITitleStateChanger* statechanger_;
	TitleState changestate_;
public:
	TitleOptionData(int x, int y, const char word[128], unsigned int color, ITitleStateChanger* statechanger, TitleState state);
	void Opt() override;
};