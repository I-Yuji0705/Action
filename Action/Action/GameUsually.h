#pragma once
#include "GameCanvasBase.h"

//�Q�[���̒ʏ펞�ɃX�e�[�W�ȊO�̏������s�����N���X
class GameUsually : public GameCanvasBase {
public:
	GameUsually(Keyboard* keyboard, IGameStateChanger* statechanger);
	void Update() final;
};