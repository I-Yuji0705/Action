#pragma once
#include "GameSelectionBase.h"

//ゲームクリアのダンス時にステージ以外の処理を行う基底クラス
class GameDance : public GameSelectionBase {
public:
	GameDance(Keyboard* keyboard,IGameStateChanger* statechanger);
	void Initialize() final;
	void Update() final;
};