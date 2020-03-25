#pragma once
#include "GameCanvasOptionBase.h"


//ゲームメニュー時にステージ以外の処理を行う基底クラス
class GameMenu : public GameCanvasOptionBase {
	private:
public:
	GameMenu(Keyboard* keyboard,IGameStateChanger* statechanger);
};