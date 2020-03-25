#pragma once
#include "ManualCanvasOptionBase.h"

//マニュアル内で選択肢から他の状態に移行する基底クラス
class ManualUsually : public ManualCanvasOptionBase {
public:
	ManualUsually(Keyboard* keyboard,IManualStateChanger* statechanger);
};