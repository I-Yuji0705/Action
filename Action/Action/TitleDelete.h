#pragma once
#include "CanvasBase.h"
#include "TitleCanvasOptionBase.h"

//Title内のゲーム終了時の選択肢を担当する基底クラス
class TitleDelete : public TitleCanvasOptionBase {
public:
	TitleDelete(Keyboard* keyboard, ITitleStateChanger* statechanger);
};