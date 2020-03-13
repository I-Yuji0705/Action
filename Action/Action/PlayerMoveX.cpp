#include "PlayerMoveX.h"
#include <tuple>
#include "DxLib.h"
#include "Keyboard.h"
#include <vector>

PlayerMoveX::PlayerMoveX(Collision *collision, Player *player, Sound* sound) : PlayerAction(collision,player,sound) {
	firsthit_ = true;
}
//�v���C���[��X���̈ړ����s��
//	����:
//		num:�ړ����悤���鋗��
void PlayerMoveX::MoveX(float num) {
	//�v���C���[��X���̈ړ����s��
	bool hit = false;
	int hitpoint;
	std::vector<Object*> hitobject;
	std::tie(hitpoint, hitobject) = collision_->HitCheckX(num, player_);//�ړ������ۂɓ�����I�u�W�F�N�g�Ɠ�����ꏊ�̎Z�o
	if (hitpoint != 0 && !hitobject.empty()) {//��������Object����������
		if(!Push(num / 2, hitobject))//�I�u�W�F�N�g������
			playerhit_->HitProcess(hitpoint, *hitobject.begin());//Hit�������̃v���C���[�̈ʒu�𒲐�����
		if (firsthit_) {//Object�ɐڐG���n�߂��Ƃ�
			firsthit_ = false;
			sound_->PlaySe(Se_Hit, player_);
		}
		hit = true;
	}
	if (player_->carryon_ != nullptr) {//�����w�����Ă���Ƃ�
		player_->carryon_->Update();
		std::tie(hitpoint, hitobject) = collision_->HitCheckX(num, player_->carryon_);//�w�����Ă��镨�̓����蔻����`�F�b�N����
		if (hitpoint != 0 && !hitobject.empty()) {//��������Object����������
			if(!Push(num / 2, hitobject))//�I�u�W�F�N�g������
				playerhit_->HitProcess(hitpoint, *hitobject.begin(), player_->carryon_);//Hit�������̃v���C���[�̈ʒu�𒲐�����
			if (firsthit_) {//Object�ɐڐG���n�߂��Ƃ�
				firsthit_ = false;
				sound_->PlaySe(Se_Hit, player_);
			}
			hit = true;
		}
	}
	int mapcheck = collision_->MapCheck(player_->Left() + num, player_);
	if (mapcheck != 0) {//�}�b�v�O�Ɉړ����Ă��܂����m�F���鏈��
		playerhit_->MapHit(mapcheck);
		hit = true;
		if (firsthit_) {
			firsthit_ = false;
			sound_->PlaySe(Se_Hit, player_);
		}
	}
	if (!hit) {//�ړ���ɉ����I�u�W�F�N�g���Ȃ��A�}�b�v�O�Ɉړ����Ȃ��ꍇ
		if(abs(num) == kMoveSpeed)//�v���C���[�̍ŏ��̈ړ������������Ƃ�
			firsthit_ = true;//����Object�ɐڐG�����ۂɉ�����悤�ɂ���
		player_->x_ += num;
	}
}
//-----------------
//Object�������o���A�����ł��������Ƃ��ł�������Ԃ�
//		����:
//				num:�������Ƃ��鋗���̏����l
//				target:�������Ƃ���Ώ�
//		�Ԃ�l:
//				true:Object�������o�����Ƃ��ł���
//				false:Object�������o���Ȃ�����
bool PlayerMoveX::Push(float num, std::vector<Object*> target) {
	float canpushed = 0.0f;
	bool push = false;
	if (player_->player_state_ == Player_Land) {//�n��ɂ���Ƃ�
		for (auto i : target) {
			if (i == *target.begin() || canpushed > i->CanPushed(num)) {//
				canpushed = i->CanPushed(num);//�����o���鋗�����Z�o
			}
		}
		for (auto i : target) {
			i->Pushed(canpushed);
		}
		MoveX(canpushed);
	}
	if (canpushed != 0.0f) push = true;
	return push;
}