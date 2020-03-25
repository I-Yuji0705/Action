#pragma once
#include "GameCanvasBase.h"

//ゲームクリアのダンス時にステージ以外の処理を行う基底クラス
class GameDance : public GameCanvasBase {
public:
	GameDance(Keyboard* keyboard,IGameStateChanger* statechanger);
};