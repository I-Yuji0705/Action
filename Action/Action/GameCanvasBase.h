#pragma once
#include "BaseScene.h"
#include "IGameStateChanger.h"
#include "CanvasBase.h"

//GameScene���ł̃X�e�[�W�ȊO�̏�����S��������N���X
class GameCanvasBase : public CanvasBase {
protected:
	IGameStateChanger *statechanger_;
public:
	GameCanvasBase(Keyboard* keyboard,IGameStateChanger* statechanger);
	virtual void Update() {};
};