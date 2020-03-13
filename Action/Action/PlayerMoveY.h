#pragma once
#include "PlayerAction.h"

//Player‚ÌY²‚ÌˆÚ“®‚ğ’S“–‚·‚é’ŠÛƒNƒ‰ƒX
class PlayerMoveY : public PlayerAction {
protected:
	void MoveY(float num);
public:
	PlayerMoveY(Collision *collision, Player *player, Sound* sound);
	//void Do() override = 0;
};