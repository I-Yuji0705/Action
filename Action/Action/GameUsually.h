#pragma once
#include "GameCanvasBase.h"

//ゲームの通常時にステージ以外の処理を行う基底クラス
class GameUsually : public GameCanvasBase {
public:
	GameUsually(Keyboard* keyboard, IGameStateChanger* statechanger);
	void Update() final;
};