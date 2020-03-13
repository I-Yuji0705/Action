#pragma once
#include "ManualSelectionBase.h"

//マニュアル内でステージ内の情報を表示する基底クラス
class ManualStage : public ManualSelectionBase {
public:
	ManualStage(Keyboard* keyboard, IManualStateChanger* statechanger);
	void Initialize() final;
};