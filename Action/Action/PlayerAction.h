#pragma once
#include "IActionBase.h"
#include "Player.h"
#include "Collision.h"

class Player;
//Player�̍s����S�����钊�ۃN���X
//PlayerDance�������AKeyboard������͂��󂯕t���A�Ή�����������s��
class PlayerAction : public IActionBase {
protected:
	Player *player_;//�s������v���C���[
public:
	PlayerAction(Player *player);
	//virtual void Do() = 0;
};