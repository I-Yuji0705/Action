#include "PlayerMoveX.h"
#include <tuple>
#include "DxLib.h"
#include "Keyboard.h"
#include <vector>
#include <algorithm>
#include "VectorNoduplicationInsert.h"

PlayerMoveX::PlayerMoveX(Sound* sound, Collision *collision, Player *player, PlayerHit* playerhit) : PlayerAction(player) {
	sound_ = sound;
	collision_ = collision;
	playerhit_ = playerhit;
	firsthit_ = true;
}
//�v���C���[��X���̈ړ����s��
//	����:
//		num:�ړ����悤���鋗��
void PlayerMoveX::MoveX(float num) {
	//�v���C���[��X���̈ړ����s��
	bool hit = false;
	int hitpoint;
	float distance;
	std::vector<Object*> hitobjects;
	std::tie(hitpoint, distance, hitobjects) = collision_->HitCheckX(num, player_);//�ړ������ۂɓ�����I�u�W�F�N�g�Ɠ�����ꏊ�̎Z�o
	if (player_->carryon_ != nullptr) {
		float carryondistance;
		std::vector<Object*> carryonhitobjects;
		int carryonhitpoint;
		std::tie(carryonhitpoint, carryondistance, carryonhitobjects) = collision_->HitCheckX(num, player_->carryon_);//�w�����Ă��镨�̓����蔻����`�F�b�N����
		if (!carryonhitobjects.empty() && carryonhitpoint != 0) {
			hitpoint = carryonhitpoint;
			hitobjects = VectorNoDuplicationInsert(hitobjects, carryonhitobjects);
			if (distance == 0 || (std::abs(distance) > std::abs(carryondistance) && carryondistance != 0))
				distance = carryondistance;
		}
	}
	if (hitpoint != 0 && !hitobjects.empty()) {//��������Object����������
		if(!Push(num, hitobjects, hitpoint))//�I�u�W�F�N�g������
			playerhit_->HitObjects(hitpoint, distance);//Hit�������̃v���C���[�̈ʒu�𒲐�����
		if (firsthit_) {//Object�ɐڐG���n�߂��Ƃ�
			sound_->PlaySe(Se_Hit, player_);
			firsthit_ = false;
		}
		hit = true;
	}
	std::tie(hitpoint,distance)= collision_->MapCheck(player_->Left() + num, player_);
	if (hitpoint != 0) {//�}�b�v�O�Ɉړ����Ă��܂����m�F���鏈��
		playerhit_->HitObjects(hitpoint,distance);
		hit = true;
		if (firsthit_) {
			firsthit_ = false;
			sound_->PlaySe(Se_Hit, player_);
		}
	}
	if (!hit) {//�ړ���ɉ����I�u�W�F�N�g���Ȃ��A�}�b�v�O�Ɉړ����Ȃ��ꍇ
		player_->x_ += num;
		firsthit_ = true;
	}
}
bool PlayerMoveX::Push(float num, std::vector<Object*> target, int check) {
	bool push = false;
	if (player_->player_state_ == Player_Land) {//�n��ɂ���Ƃ�
		float canpushed;
		std::vector<Object*> pushtarget;
		std::tie(pushtarget, canpushed) = collision_->AlignAdhesionObjects(target, player_, check);
		if (player_->carryon_ != nullptr) {
			float carryoncanpushed;
			std::vector<Object*> carryonpushtarget;
			std::tie(carryonpushtarget, carryoncanpushed) = 
				collision_->AlignAdhesionObjects(target, player_->carryon_, check);
			if (!carryonpushtarget.empty()) {
				pushtarget = VectorNoDuplicationInsert(pushtarget, carryonpushtarget);
				if (canpushed == 0 || (std::abs(canpushed) > std::abs(carryoncanpushed) && carryoncanpushed != 0))
					canpushed = carryoncanpushed;
			}
		}
		if (!pushtarget.empty()) {
			for (auto i : pushtarget) {
				if (std::abs(canpushed) > std::abs(i->CanPushed(num / 2))) {//
					canpushed = i->CanPushed(num / 2);//�����o���鋗�����Z�o
				}
			}
			for (auto i : pushtarget) {
				i->Pushed(canpushed);
			}
			push = true;
			player_->Set(player_->Left() + canpushed, player_->Top());
		}
	}
	return push;
}