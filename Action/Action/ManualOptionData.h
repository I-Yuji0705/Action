#pragma once
#include "OptionDataBase.h"
#include "IManualStateChanger.h"

//マニュアル内で選択肢を表示する表示する抽象クラス
class ManualOptionData : public OptionDataBase {
private:
	IManualStateChanger* statechanger_;
	ManualState changestate_;
public:
	ManualOptionData(int x, int y, const char word[128], unsigned int color, IManualStateChanger* statechanger, ManualState state);
	void Opt() override;
};
