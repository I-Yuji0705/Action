#pragma once
#include "GameSelectionBase.h"


//�Q�[�����j���[���ɃX�e�[�W�ȊO�̏������s�����N���X
class GameMenu : public GameSelectionBase {
	private:
		//void SelectionColorChange();
public:
	GameMenu(Keyboard* keyboard,IGameStateChanger* statechanger);
	void Initialize() final;
	void Update() final;
};