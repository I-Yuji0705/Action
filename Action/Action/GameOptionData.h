#pragma once
#include "OptionDataBase.h"
#include "IGameStateChanger.h"

class IGameStateChanger;
class GameOptionData : public OptionDataBase {
private:
	IGameStateChanger* statechanger_;
	GameState changestate_;
public:
	GameOptionData(int x, int y, const char word[128], unsigned int color, IGameStateChanger* statechanger, GameState state);
	void Opt() override;
};