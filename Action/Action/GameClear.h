#pragma once
#include "GameSelectionBase.h"
#include "SelectionDeta.h"

//ゲームクリア時にステージ以外の処理を行う基底クラス
class GameClear : public GameSelectionBase {
public:
	GameClear(IGameStateChanger *statechanger);
	void Initialize() final;
	void Update() final;
};