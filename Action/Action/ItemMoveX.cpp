#include "ItemMoveX.h"
#include <tuple>

///<summary>
///<para>�R���X�g���N�^</para>
///<para>�����Ǘ�����N���X�ƐڐG�𔻒肷��N���X�A�ڐG��̏������s���N���X�̃|�C���^��ǉ��Ŏ�������</para>
///<param name="sound"><para>sound:�ǂɐڐG�����ۂɖ炷�����Ǘ�����N���X�̃|�C���^</para></param>
///<param name="collision"><para>collision:�ړ������ɏՓ˂���Object�����邩�𒲂ׂ�N���X�̃|�C���^</para></param>
///<param name="itemhit"><para>itemhit:�ڐG���Ɉʒu�����Ȃǂ̏������s���N���X�̃|�C���^</para></param>
///</summary>
ItemMoveX::ItemMoveX(Sound* sound, Collision *collision, Item *item,ItemHit* itemhit) : ItemAction(item) {
	sound_ = sound;
	collision_ = collision;
	itemhit_ = itemhit;
}

///<summary>
///<para>Y���̈ړ�����</para>
///<para>�ړ����悤�Ƃ��Ă��鐔�����󂯎��A�ړ���ɑ���Object�ɐڐG���邩�𒲂ׂ�</para>
///<para>�ړ����Object�Ȃ��ꍇ:x�ɐ��l�����Z���A�ړ�����</para>
///<para>�ړ����Object����ꍇ:�ڐG�������s��</para>
///<param name="num"><para>num:X���ɉ��Z���悤�Ƃ��Ă���l</para></param>
///</summary>
void ItemMoveX::MoveX(float num) {
	bool hit = false;
	int hitpoint;
	float distance;
	std::vector<Object*> hitobjects;
	std::tie(hitpoint, distance, hitobjects) = collision_->HitCheckX(num, item_);//�ړ������ۂɓ�����I�u�W�F�N�g�Ɠ�����ꏊ�̎Z�o
	if (hitpoint != 0 && !hitobjects.empty()) {//��������Object����������
		itemhit_->HitObjects(hitpoint, distance);//Hit��������Item�̈ʒu�𒲐�����
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

///<summary>
///<para>�s������</para>
///<para>item_�̌�������ړ�������߁AX���̈ړ��������s��</para>
///</summary>
void ItemMoveX::Do() {
	const float kThrowSpeed = 10.0f;
	MoveX(kThrowSpeed * item_->vector_);
}