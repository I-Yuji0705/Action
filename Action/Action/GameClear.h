#pragma once
#include "GameCanvasBase.h"
#include "TextDeta.h"

//ゲームクリア時にステージ以外の処理を行う基底クラス
class GameClear : public GameCanvasBase {
public:
	GameClear(Keyboard* keyboard,IGameStateChanger *statechanger);
	void Update() final;
};