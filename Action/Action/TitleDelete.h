#pragma once
#include "TitleSelectionBase.h"

//Title���̃Q�[���I�����̑I������S��������N���X
class TitleDelete : public TitleSelectionBase {
public:
	TitleDelete(Keyboard* keyboard, ITitleStateChanger* statechanger);
	void Initialize() final;
	void Update() final;
};