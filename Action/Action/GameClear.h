#pragma once
#include "GameSelectionBase.h"
#include "SelectionDeta.h"

//�Q�[���N���A���ɃX�e�[�W�ȊO�̏������s�����N���X
class GameClear : public GameSelectionBase {
public:
	GameClear(IGameStateChanger *statechanger);
	void Initialize() final;
	void Update() final;
};