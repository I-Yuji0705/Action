#include "PlayerHit.h"
#include <assert.h>
PlayerHit::PlayerHit(Collision* collision,Player* player) : Hit(collision) {
	player_ = player;
	collision->GetMapLeft(map_left_);
	collision->GetMapRight(map_right_);
}
void PlayerHit::HitObjects(int check, float distance) {
	int hitangle = 60;
	switch (check) {
	case 1:
	case 2:
		player_->Set(player_->Left() + distance, player_->Top());
		break;
	case 3:
		player_->Set(player_->Left(), player_->Top() + distance);
		player_->player_state_ = Player_Land;
		break;
	case 4:
		player_->angle_ = hitangle;
		player_->Set(player_->Left(), player_->Top() + distance);
		break;
	default:
		assert(false);
		break;
	}
}