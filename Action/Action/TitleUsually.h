#pragma once
#include "TitleSelectionBase.h"

//Menu���ōŏ��ɕ\��������N���X
class TitleUsually : public TitleSelectionBase {
public:
	TitleUsually(Keyboard* keyboard, ITitleStateChanger* statechanger);
	void Initialize() final;
	void Update() final;
};