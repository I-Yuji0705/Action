#include "PlayerDance.h"


PlayerDance::PlayerDance(Player *player) : PlayerAction(player) {
	dancetimer_ = 0;
	choreographnum_ = 0;
}
//���̐U�t�Ɉڍs����
void PlayerDance::NextChoreoGrap() {
	dancetimer_ = 0;
	choreographnum_++;
}
void PlayerDance::Do() {
	//�U�t�̔ԍ��ɂ���ăv���C���[�̈ړ��ƌ�����ύX����
	switch (choreographnum_) {
	case 0:
		player_->vector_ = -1;
		player_->y_ -= 2;
		dancetimer_++;
		if (dancetimer_ > 15) {
			NextChoreoGrap();
		}
		break;
	case 1:
		player_->vector_ = -1;
		player_->y_ += 2;
		dancetimer_++;
		if (dancetimer_ > 15) {
			NextChoreoGrap();
		}
		break;
	case 2:
		player_->vector_ = 1;
		player_->y_ -= 2;
		dancetimer_++;
		if (dancetimer_ > 45) {
			NextChoreoGrap();
		}
		break;
		//�S�Ă̐U�t���I������ۂ�ClearState�ɕς���
	default:
		player_->state_changer_->ChangeState(Game_Clear);
		break;
	}
}