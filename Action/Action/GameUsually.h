#pragma once
#include "GameSelectionBase.h"

//�Q�[���̒ʏ펞�ɃX�e�[�W�ȊO�̏������s�����N���X
class GameUsually : public GameSelectionBase {
public:
	GameUsually(IGameStateChanger* statechanger);
	void Initialize() final;
	void Update() final;
};