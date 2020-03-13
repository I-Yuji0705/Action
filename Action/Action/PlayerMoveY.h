#pragma once
#include "PlayerAction.h"
#include "Gravity.h"
//PlayerのY軸の移動を担当する抽象クラス
class PlayerMoveY : public PlayerAction {
protected:
	Gravity gravity_;
	Collision* collision_;//アクション時の物理判定を計測する場所
	Sound* sound_;//アクション時に鳴らす音
	PlayerHit* playerhit_;
	void MoveY(float num);
public:
	PlayerMoveY(Sound* sound, Collision *collision, Player *player,PlayerHit* hit);
};