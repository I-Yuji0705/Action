#include "TitleCanvasOptionBase.h"

TitleCanvasOptionBase::TitleCanvasOptionBase(Keyboard* keyboard, ITitleStateChanger* statechanger) : CanvasOptionBase(keyboard) {
	statechanger_ = statechanger;
}