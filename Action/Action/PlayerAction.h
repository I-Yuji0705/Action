#pragma once
#include "IActionBase.h"
#include "Player.h"
#include "Collision.h"
#include "PlayerHit.h"

class Player;
class PlayerHit;
//Player�̍s����S�����钊�ۃN���X
class PlayerAction : public IActionBase {
protected:
	Player *player_;//�s������v���C���[
public:
	PlayerAction(Player *player);
	//virtual void Do() = 0;
};