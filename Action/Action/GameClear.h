#pragma once
#include "GameCanvasBase.h"
#include "TextDeta.h"

//�Q�[���N���A���ɃX�e�[�W�ȊO�̏������s�����N���X
class GameClear : public GameCanvasBase {
public:
	GameClear(Keyboard* keyboard,IGameStateChanger *statechanger);
	void Update() final;
};