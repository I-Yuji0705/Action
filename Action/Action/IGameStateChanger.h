#pragma once

enum class GameState {
	Game_Usually,//ゲーム通常時
	Game_Menu,//ゲーム内でのメニュー画面
	Game_Dance,//クリア条件を満たした際のダンス画面
	Game_Clear,//ダンス後のクリア画面
	Game_Retry,//リトライ処理の要請
	Game_Exit,//ゲームを終了し、メニューに戻る要請

	Game_None//要請無し
};

//Game内のStateだけを変更するためのインターフェースクラス
class IGameStateChanger {
public:
	virtual ~IGameStateChanger() = 0;
	virtual void ChangeState(GameState state) = 0;
};