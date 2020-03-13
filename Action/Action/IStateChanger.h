#pragma once
enum State {
	Game_Normal,
	Game_Retry,
	Game_Dance,
	Game_Clear,
};
class IStateChanger {
public:
	virtual ~IStateChanger() = 0;
	virtual void ChangeState(State state) = 0;
};