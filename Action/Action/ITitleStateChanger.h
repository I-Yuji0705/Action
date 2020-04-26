#pragma once

enum TitleState {
	Title_Usually,
	Title_Delete,
	Title_Game,
	Title_Exit,
	Title_Intersection,

	Title_None//無し
};
//Title内のStateだけを変更するためのインターフェースクラス
class ITitleStateChanger {
public:
	virtual ~ITitleStateChanger() = 0;
	virtual void ChangeState(TitleState state) = 0;
	virtual void ChangeState(TitleState state, const char stagename[30]) = 0;
};