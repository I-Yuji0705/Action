#include "PlayerMoveLeft.h"



PlayerMoveLeft::PlayerMoveLeft(Collision *collision, Player *player, Sound* sound) : PlayerMoveX(collision,player,sound) {
}
//�v���C���[��X���̈ړ����s��
//	����:
//		num:�ړ����悤���鋗��
void PlayerMoveLeft::Do() {
	player_->vector_ = -1;
	MoveX(-kMoveSpeed);
}