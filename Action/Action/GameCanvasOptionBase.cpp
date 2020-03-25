#include "GameCanvasOptionBase.h"

GameCanvasOptionBase::GameCanvasOptionBase(Keyboard* keyboard, IGameStateChanger* statechanger) : CanvasOptionBase(keyboard) {
	statechanger_ = statechanger;
}