#pragma once
#include "ManualSelectionBase.h"

//マニュアル内で選択肢から他の状態に移行する基底クラス
class ManualUsually : public ManualSelectionBase {
public:
	ManualUsually(IManualStateChanger* statechanger);
	void Initialize() final;
	void Update() final;
};