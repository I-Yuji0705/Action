#pragma once
#include "CanvasBase.h"
#include "TitleCanvasOptionBase.h"

//Title���̃Q�[���I�����̑I������S��������N���X
class TitleDelete : public TitleCanvasOptionBase {
public:
	TitleDelete(Keyboard* keyboard, ITitleStateChanger* statechanger);
};