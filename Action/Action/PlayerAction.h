#pragma once
#include "ActionBase.h"
#include "Player.h"
#include "Collision.h"
#include "PlayerHit.h"

class Player;
class PlayerHit;
//Player�̍s����S�����钊�ۃN���X
class PlayerAction : public ActionBase {
protected:
	Player *player_;//�s������v���C���[
	PlayerHit *playerhit_;
public:
	PlayerAction(Collision *collision, Player *player, Sound* sound);
	//virtual void Do() = 0;
};