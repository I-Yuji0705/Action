#include "PlayerMoveLeft.h"



PlayerMoveLeft::PlayerMoveLeft(Sound* sound, Collision *collision, Player *player, PlayerHit* playerhit) : PlayerMoveX(sound, collision, player,playerhit) {
}
//�v���C���[��X���̈ړ����s��
//	����:
//		num:�ړ����悤���鋗��
void PlayerMoveLeft::Do() {
	player_->vector_ = -1;
	MoveX(-kMoveSpeed);
}