#pragma once
#include "BaseScene.h"
#include "IGameStateChanger.h"
#include "CanvasBase.h"

//GameScene内でのステージ以外の処理を担当する基底クラス
class GameCanvasBase : public CanvasBase {
protected:
	IGameStateChanger *statechanger_;
public:
	GameCanvasBase(Keyboard* keyboard,IGameStateChanger* statechanger);
	virtual void Update() {};
};