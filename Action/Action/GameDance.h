#pragma once
#include "GameSelectionBase.h"

//�Q�[���N���A�̃_���X���ɃX�e�[�W�ȊO�̏������s�����N���X
class GameDance : public GameSelectionBase {
public:
	GameDance(IGameStateChanger* statechanger);
	void Initialize() final;
	void Update() final;
};