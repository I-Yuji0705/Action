#pragma once
#include "ManualCanvasBase.h"

//マニュアル内でゲームのクリア条件を表示する基底クラス
class ManualRule : public ManualCanvasBase {
public:
	ManualRule(Keyboard* keyboard, IManualStateChanger* statechanger);
};