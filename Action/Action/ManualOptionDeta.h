#pragma once
#include "OptionDetaBase.h"
#include "IManualStateChanger.h"

//マニュアル内で選択肢を表示する表示する抽象クラス
class ManualOptionDeta : public OptionDetaBase {
private:
	IManualStateChanger* statechanger_;
	ManualState changestate_;
public:
	ManualOptionDeta(int x, int y, const char word[128], unsigned int color, IManualStateChanger* statechanger, ManualState state);
	void Opt() override;
};
