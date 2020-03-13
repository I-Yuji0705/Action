#include "GameSelectionBase.h"
#include "DxLib.h"

GameSelectionBase::GameSelectionBase(IGameStateChanger* statechanger) {
	statechanger_ = statechanger;
}