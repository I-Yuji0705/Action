#include "ManualCanvasOptionBase.h"
#include "DxLib.h"

ManualCanvasOptionBase::ManualCanvasOptionBase(Keyboard* keyboard, IManualStateChanger* statechanger)  : CanvasOptionBase(keyboard){
	statechanger_ = statechanger;
}