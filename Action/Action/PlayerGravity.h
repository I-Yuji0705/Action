#pragma once
#include "PlayerMoveY.h"
#include "Gravity.h"
//Playerの重力(下方向)移動を担当する基底クラス
class PlayerGravity : public PlayerMoveY {
public:
	PlayerGravity(Sound* sound, Collision *collision, Player *player,PlayerHit* hit);
	void Do() final;
};
