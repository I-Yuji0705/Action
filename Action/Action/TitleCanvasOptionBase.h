#pragma once
#include "BaseScene.h"
#include "ITitleStateChanger.h"
#include "CanvasOptionBase.h"

//TitleScene“à‚Å‚Ì‘I‘ðŽˆ‚ð’S“–‚·‚éŠî’êƒNƒ‰ƒX
class TitleCanvasOptionBase : public CanvasOptionBase {
protected:
	ITitleStateChanger* statechanger_;
public:
	TitleCanvasOptionBase(Keyboard* keyboard, ITitleStateChanger* statechanger);
};
