#include "GameSelectionBase.h"
#include "DxLib.h"

GameSelectionBase::GameSelectionBase(Keyboard* keyboard,IGameStateChanger* statechanger) :SelectionBase(keyboard) {
	statechanger_ = statechanger;
}