#include "PlayerMoveLeft.h"



PlayerMoveLeft::PlayerMoveLeft(Sound* sound, Collision *collision, Player *player, PlayerHit* playerhit) : PlayerMoveX(sound, collision, player,playerhit) {
}
//プレイヤーのX軸の移動を行う
//	引数:
//		num:移動しようする距離
void PlayerMoveLeft::Do() {
	player_->vector_ = -1;
	MoveX(-kMoveSpeed);
}