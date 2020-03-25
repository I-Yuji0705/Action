#pragma once
#include "OptionDetaBase.h"
#include "IGameStateChanger.h"

class IGameStateChanger;
class GameOptionDeta : public OptionDetaBase {
private:
	IGameStateChanger* statechanger_;
	GameState changestate_;
public:
	GameOptionDeta(int x, int y, const char word[128], unsigned int color, IGameStateChanger* statechanger, GameState state);
	void Opt() override;
};