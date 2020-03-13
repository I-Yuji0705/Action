#include "ItemThrew.h"
#include <tuple>

ItemThrew::ItemThrew(Sound* sound, Collision *collision, Item *item,ItemHit* itemhit) : ItemAction(item) {
	sound_ = sound;
	collision_ = collision;
	itemhit_ = itemhit;
}

void ItemThrew::MoveX(float num) {
	//�v���C���[��X���̈ړ����s��
	bool hit = false;
	int hitpoint;
	float distance;
	std::vector<Object*> hitobjects;
	std::tie(hitpoint, distance, hitobjects) = collision_->HitCheckX(num, item_);//�ړ������ۂɓ�����I�u�W�F�N�g�Ɠ�����ꏊ�̎Z�o
	if (hitpoint != 0 && !hitobjects.empty()) {//��������Object����������
		itemhit_->HitObjects(hitpoint, distance);//Hit�������̃v���C���[�̈ʒu�𒲐�����
		if(distance != 0.0f)
			sound_->PlaySe(Se_Hit, item_);
		hit = true;
	}
	std::tie(hitpoint, distance) = collision_->MapCheck(item_->Left() + num, item_);
	if (hitpoint != 0) {//�}�b�v�O�Ɉړ����Ă��܂����m�F���鏈��
  		itemhit_->HitObjects(hitpoint, distance);
		hit = true;
		sound_->PlaySe(Se_Hit, item_);
	}
	if (!hit) {
		item_->x_ += num;
	}
}

void ItemThrew::Do() {
	const float kThrowSpeed = 10.0f;
	MoveX(kThrowSpeed * item_->vector_);
}