#pragma once
#include "BaseScene.h"
#include "IGameStateChanger.h"
#include "SelectionBase.h"

//GameScene���ł̃X�e�[�W�ȊO�̏�����S��������N���X
class GameSelectionBase : public SelectionBase {
protected:
	IGameStateChanger *statechanger_;
public:
	GameSelectionBase(Keyboard* keyboard,IGameStateChanger* statechanger);
	virtual void Update() {};
};