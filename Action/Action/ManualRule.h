#pragma once
#include "ManualSelectionBase.h"

//マニュアル内でゲームのクリア条件を表示する基底クラス
class ManualRule : public ManualSelectionBase {
public:
	ManualRule(Keyboard* keyboard, IManualStateChanger* statechanger);
	void Initialize()final;
};