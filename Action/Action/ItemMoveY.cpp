#include "ItemMoveY.h"
#include <tuple>

///<summary>
///<para>�R���X�g���N�^</para>
///<para>�����Ǘ�����N���X�ƐڐG�𔻒肷��N���X�A�ڐG��̏������s���N���X�̃|�C���^��ǉ��Ŏ�������</para>
///<param name="sound"><para>sound:�ǂɐڐG�����ۂɖ炷�����Ǘ�����N���X�̃|�C���^</para></param>
///<param name="collision"><para>collision:�ړ������ɏՓ˂���Object�����邩�𒲂ׂ�N���X�̃|�C���^</para></param>
///<param name="sound"><para>itemhit:�ڐG���Ɉʒu�����Ȃǂ̏������s���N���X�̃|�C���^</para></param>
///</summary>
ItemMoveY::ItemMoveY(Sound* sound, Collision *collision, Item *item, ItemHit* itemhit) : ItemAction(item) {
	sound_ = sound;
	collision_ = collision;
	itemhit_ = itemhit;
}


///<summary>
///<para>Y���̈ړ�����</para>
///<para>�ړ����悤�Ƃ��Ă��鐔�����󂯎��A�ړ���ɑ���Object�ɐڐG���邩�𒲂ׂ�</para>
///<para>�ړ����Object�Ȃ��ꍇ:y_�ɐ��l�����Z���A�ړ�����</para>
///<para>�ړ����Object����ꍇ:�ڐG�������s��</para>
///<param name="num"><para>num:Y���ɉ��Z���悤�Ƃ��Ă���l</para></param>
///</summary>
void ItemMoveY::MoveY(float num) {
	bool hit = false;
	int hitpoint;
	float distance;
	std::vector<Object*> hitobject;
	std::tie(hitpoint, distance, hitobject) = collision_->HitCheckY(num, item_);
	if (hitpoint != 0  &&!hitobject.empty()) {
		itemhit_->HitObjects(hitpoint, distance);
		hit = true;
	}
	if (!hit) {
		item_->Set(item_->Left(), item_->Top() + num);
	}
}

///<summary>
///<para>�s������</para>
///<para>�d�͕��AY���̈ړ��������s��</para>
///</summary>
void ItemMoveY::Do() {
	MoveY(gravity_.kGravity);
}