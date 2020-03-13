#include "PlayerMoveY.h"
#include <tuple>

PlayerMoveY::PlayerMoveY(Sound* sound, Collision *collision, Player *player, PlayerHit* playerhit) : PlayerAction(player) {
	sound_ = sound;
	collision_ = collision;
	playerhit_ = playerhit;
}
void PlayerMoveY::MoveY(float num) {
	//�v���C���[��X���̈ړ����s��
	bool hit = false;
	int hitpoint;
	float distance;
	std::vector<Object*> hitobjects; 
	if (player_->carryon_ != nullptr) {//�����w�����Ă���Ƃ�
		player_->carryon_->Update();
		std::tie(hitpoint, distance, hitobjects) = collision_->HitCheckY(num, player_->carryon_);//�w�����Ă��镨�̓����蔻����`�F�b�N����
		if (hitpoint != 0 && !hitobjects.empty() &&
			*hitobjects.begin() != player_) {//��������Object����������
			std::tie(hitobjects, distance) = collision_->AlignAdhesionObjects(hitobjects, player_->carryon_, hitpoint);
			if (distance != 999.0f)
				playerhit_->HitObjects(hitpoint, distance);//Hit�������̃v���C���[�̈ʒu�𒲐�����
			if (distance != 0.0f && distance != 999.0f)
				sound_->PlaySe(Se_Hit, player_);
			hit = true;
		}
	}
	std::tie(hitpoint, distance, hitobjects) = collision_->HitCheckY(num, player_);//�ړ������ۂɓ�����I�u�W�F�N�g�Ɠ�����ꏊ�̎Z�o
	if (hitpoint != 0  && !hitobjects.empty() && 
		*hitobjects.begin() != player_->carryon_) {//��������Object����������
		playerhit_->HitObjects(hitpoint, distance);//Hit�������̃v���C���[�̈ʒu�𒲐�����
		if(distance != 0.0f)
			sound_->PlaySe(Se_Hit, player_);
		hit = true;
	}
	if (!hit) {
		player_->y_ += num;
		player_->player_state_ = Player_Air;
	}
}