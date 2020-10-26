#pragma once

enum class TitleState {
	Title_Usually,//初期画面
	Title_Delete, //終了確認画面
	Title_Game, //ゲームシーンに移行
	Title_Exit, //ゲーム終了
	Title_Intersection, //説明シーンに移行
	Title_StageSelect, //ステージ選択画面に移行

	Title_None//無し
};
//Title内のStateだけを変更するためのインターフェースクラス
class ITitleStateChanger {
public:
	virtual ~ITitleStateChanger() = 0;
	virtual void ChangeState(TitleState state) = 0;
	virtual void ChangeState(TitleState state, const char stagename[30]) = 0;
};