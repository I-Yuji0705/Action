#pragma once
#include "TitleSelectionBase.h"

//TitleΰΜQ[IΉΜIππS·ιξκNX
class TitleDelete : public TitleSelectionBase {
public:
	TitleDelete(Keyboard* keyboard, ITitleStateChanger* statechanger);
	void Initialize() final;
	void Update() final;
};