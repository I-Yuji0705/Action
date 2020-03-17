#pragma once
#include "PlayerAction.h"
#include "Gravity.h"
#include "Keyboard.h"
#include "PlayerHit.h"

class Keyboard;
class Collison;
class Sound;
class PlayerHit;

//PlayerのY軸の移動を担当する抽象クラス
class PlayerMoveY : public PlayerAction {
protected:
	Keyboard *keyboard_;
	Collision* collision_;//アクション時の物理判定を計測する場所
	Sound* sound_;//アクション時に鳴らす音
	PlayerHit* playerhit_;
	Gravity gravity_;
	const float kJumpPower = 8.0f;//Jump時の基礎速度
	void MoveY(float num);
public:
	PlayerMoveY(Keyboard* keyboard,Sound* sound, Collision *collision, Player *player,PlayerHit* hit);
	void Do() override;
};