#pragma once
#include "ManualCanvasBase.h"

//マニュアル内で操作方法を表示する基底クラス
class ManualOperation : public ManualCanvasBase {
public:
	ManualOperation(Keyboard* keyboard, IManualStateChanger* statechanger);
};