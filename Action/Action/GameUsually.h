#pragma once
#include "GameSelectionBase.h"

//ゲームの通常時にステージ以外の処理を行う基底クラス
class GameUsually : public GameSelectionBase {
public:
	GameUsually(Keyboard* keyboard, IGameStateChanger* statechanger);
	void Initialize() final;
	void Update() final;
};