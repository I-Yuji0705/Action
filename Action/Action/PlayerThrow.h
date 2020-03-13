#pragma once
#include "PlayerAction.h"

//Playerの投げる処理を担当する基底クラス
class PlayerThrow : public PlayerAction {
private:
	Sound* sound_;//アクション時に鳴らす音
public:
	PlayerThrow(Sound* sound, Player *player);
	void Do() final;
};