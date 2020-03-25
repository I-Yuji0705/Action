#pragma once
#include "ManualCanvasBase.h"

//マニュアル内でステージ内の情報を表示する基底クラス
class ManualStage : public ManualCanvasBase {
public:
	ManualStage(Keyboard* keyboard, IManualStateChanger* statechanger);
};