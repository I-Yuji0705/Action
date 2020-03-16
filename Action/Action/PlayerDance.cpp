#include "PlayerDance.h"

///<summary>
///<para>�R���X�g���N�^</para>
///<para>�ǉ���Dance�Ɏg�p����ϐ��̏��������s��</para>
///</summary>
PlayerDance::PlayerDance(Player *player) : PlayerAction(player) {
	dancetimer_ = 0;
	choreographnum_ = 0;
}

///<summary>
///<para>�_���X�̎��̐U�t�Ɉڍs����</para>
///<para>�_���X�ňړ����鎞�Ԃ����Z�b�g���A�U�t�����̒i�K�Ɉڍs������</para>
///</summary>
void PlayerDance::NextChoreoGrap() {
	dancetimer_ = 0;
	choreographnum_++;
}

///<summary>
///<para>�s������</para>
///<para>�U�t�̔ԍ��ɂ���āA�ړ����鎲�A�ړ����鋗���A���Ԃ����߁A���ԂɂȂ����玟�̐U�t�Ɉڍs����</para>
///<para>�U�t���S�ďI��������AGame��state��Clear�ɕύX����</para>
///</summary>
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