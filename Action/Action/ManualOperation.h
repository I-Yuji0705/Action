#pragma once
#include "ManualSelectionBase.h"

//マニュアル内で操作方法を表示する基底クラス
class ManualOperation : public ManualSelectionBase {
public:
	ManualOperation(Keyboard* keyboard, IManualStateChanger* statechanger);
	void Initialize() final;
};