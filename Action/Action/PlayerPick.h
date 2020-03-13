#pragma once
#include "PlayerAction.h"

//Playerの拾う処理を担当する基底クラス
class PlayerPick : public PlayerAction {
private:
	Collision* collision_;//アクション時の物理判定を計測する場所
	Sound* sound_;//アクション時に鳴らす音
public:
	PlayerPick(Sound* sound, Collision *collision, Player *player);
	void Do() final;
};