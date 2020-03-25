#pragma once
#include "OptionDetaBase.h"
#include "ITitleStateChanger.h"

class ITitleStateChanger;
class TitleOptionDeta : public OptionDetaBase {
private:
	ITitleStateChanger* statechanger_;
	TitleState changestate_;
public:
	TitleOptionDeta(int x, int y, const char word[128], unsigned int color, ITitleStateChanger* statechanger, TitleState state);
	void Opt() override;
};