#pragma once
#include "PlayerAction.h"

//Playerの置く処理を担当する基底クラス
class PlayerPut : public PlayerAction {
private:
	Sound* sound_;//アクション時に鳴らす音
public:
	PlayerPut(Sound* sound, Player *player);
	void Do() final;
};