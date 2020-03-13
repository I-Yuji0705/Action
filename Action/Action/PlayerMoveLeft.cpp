#include "PlayerMoveLeft.h"



PlayerMoveLeft::PlayerMoveLeft(Collision *collision, Player *player, Sound* sound) : PlayerMoveX(collision,player,sound) {
}
//プレイヤーのX軸の移動を行う
//	引数:
//		num:移動しようする距離
void PlayerMoveLeft::Do() {
	player_->vector_ = -1;
	MoveX(-kMoveSpeed);
}