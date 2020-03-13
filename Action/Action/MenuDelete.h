#pragma once
#include "MenuSelectionBase.h"

//Menu内のゲーム終了時の選択肢を担当する基底クラス
class MenuDelete : public MenuSelectionBase {
public:
	MenuDelete(Keyboard* keyboard, IMenuStateChanger* statechanger);
	void Initialize() final;
	void Update() final;
};