#pragma once

enum GameState {
	Game_Usually,
	Game_Menu,
	Game_Retry,
	Game_Dance,
	Game_Clear,
	Game_Exit,

	Game_None//無し
};

//Game内のStateだけを変更するためのインターフェースクラス
class IGameStateChanger {
public:
	virtual ~IGameStateChanger() = 0;
	virtual void ChangeState(GameState state) = 0;
};