#include "MenuSelectionBase.h"

MenuSelectionBase::MenuSelectionBase(Keyboard* keyboard, IMenuStateChanger* statechanger) : SelectionBase(keyboard){
	statechanger_ = statechanger;
}
