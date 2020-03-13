#include "TitleSelectionBase.h"

TitleSelectionBase::TitleSelectionBase(Keyboard* keyboard, ITitleStateChanger* statechanger) : SelectionBase(keyboard){
	statechanger_ = statechanger;
}
