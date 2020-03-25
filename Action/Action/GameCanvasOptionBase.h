#pragma once
#include "BaseScene.h"
#include "IGameStateChanger.h"
#include "CanvasOptionBase.h"

//GameScene“à‚Å‚Ì€–Ú‚Ì’ŠÛƒNƒ‰ƒX
class GameCanvasOptionBase : public CanvasOptionBase {
protected:
	IGameStateChanger* statechanger_;
public:
	GameCanvasOptionBase(Keyboard* keyboard, IGameStateChanger* statechanger);
};