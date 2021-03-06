#pragma once
#include "BaseScene.h"
#include "ITitleStateChanger.h"
#include "CanvasOptionBase.h"

//TitleScene内での選択肢を担当する基底クラス
class TitleCanvasOptionBase : public CanvasOptionBase {
protected:
	ITitleStateChanger* statechanger_;
public:
	TitleCanvasOptionBase(Keyboard* keyboard, ITitleStateChanger* statechanger);
};
