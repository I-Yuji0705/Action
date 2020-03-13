#pragma once

enum MenuState {
	Menu_Usually,
	Menu_Delete,
	Menu_Game,
	Menu_Exit,
	Menu_Intersection,

	Menu_None//無し
};
//Menu内のStateだけを変更するためのインターフェースクラス
class IMenuStateChanger {
public:
	virtual ~IMenuStateChanger() = 0;
	virtual void ChangeState(MenuState state) = 0;
};