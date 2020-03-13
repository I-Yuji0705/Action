#pragma once
enum State {
	Game_Normal,
	Game_Clear,
	Game_Menu,
	Game_Retry,
};
class IStateChanger {
public:
	virtual ~IStateChanger() = 0;
	virtual void ChangeState(State state) = 0;
};