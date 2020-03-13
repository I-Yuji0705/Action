#pragma once
#include "BaseScene.h"
#include "IGameStateChanger.h"
#include "SelectionBase.h"

//GameScene内でのステージ以外の処理を担当する基底クラス
class GameSelectionBase : public SelectionBase {
protected:
	IGameStateChanger *statechanger_;
public:
	GameSelectionBase(Keyboard* keyboard,IGameStateChanger* statechanger);
	virtual void Update() {};
};