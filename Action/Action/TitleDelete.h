#pragma once
#include "TitleSelectionBase.h"

//Title内のゲーム終了時の選択肢を担当する基底クラス
class TitleDelete : public TitleSelectionBase {
public:
	TitleDelete(Keyboard* keyboard, ITitleStateChanger* statechanger);
	void Initialize() final;
	void Update() final;
};