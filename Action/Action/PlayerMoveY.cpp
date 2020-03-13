#include "PlayerMoveY.h"
#include <tuple>

PlayerMoveY::PlayerMoveY(Collision *collision, Player *player, Sound* sound) : PlayerAction(collision, player, sound) {
}
void PlayerMoveY::MoveY(float num) {
	//�v���C���[��X���̈ړ����s��
	bool hit = false;
	int hitpoint;
	std::vector<Object*> hitobject;
	std::tie(hitpoint, hitobject) = collision_->HitCheckY(num, player_);
	if (hitpoint != 0 && !hitobject.empty() && *hitobject.begin() != player_->carryon_) {
		playerhit_->HitProcess(hitpoint, *hitobject.begin());//Hit�������̃v���C���[�̈ʒu�𒲐�����
		hit = true;
		if(num < 0) sound_->PlaySe(Se_Hit, player_);
	}
	if (!hit && player_->carryon_ != nullptr) {//�����w�����Ă���Ƃ�
		player_->carryon_->Update();
		std::tie(hitpoint, hitobject) = collision_->HitCheckY(num, player_->carryon_);//�w�����Ă��镨�̓����蔻����`�F�b�N����
		if (hitpoint != 0 && !hitobject.empty() && *hitobject.begin() != player_) {
			playerhit_->HitProcess(hitpoint, *hitobject.begin(),player_->carryon_);//Hit�������̃v���C���[�̈ʒu�𒲐�����
			hit = true;
			if (num < 0) sound_->PlaySe(Se_Hit, player_);
		}
	}
	if (!hit) {
		player_->y_ += num;
		player_->player_state_ = Player_Air;
	}
}