#pragma once
#include "TitleOptionData.h"

class TitleToGameOptionData : public TitleOptionData {
private:
	char stagename_[30];
public:
	TitleToGameOptionData(int x, int y, const char word[128], unsigned int color, ITitleStateChanger* statechanger, TitleState state,const char stagename[30]);
	void Opt() override;
};