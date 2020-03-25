#pragma once
#include "BaseScene.h"
#include "IGameStateChanger.h"
#include "CanvasOptionBase.h"

//GameScene���ł̍��ڂ̒��ۃN���X
class GameCanvasOptionBase : public CanvasOptionBase {
protected:
	IGameStateChanger* statechanger_;
public:
	GameCanvasOptionBase(Keyboard* keyboard, IGameStateChanger* statechanger);
};