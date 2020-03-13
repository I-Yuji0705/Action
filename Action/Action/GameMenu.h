#pragma once
#include "GameSelectionBase.h"


//ゲームメニュー時にステージ以外の処理を行う基底クラス
class GameMenu : public GameSelectionBase {
	private:
		//void SelectionColorChange();
public:
	GameMenu(Keyboard* keyboard,IGameStateChanger* statechanger);
	void Initialize() final;
	void Update() final;
};