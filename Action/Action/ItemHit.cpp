#include "ItemHit.h"
#include <assert.h>

///<summary>
///<para>�R���X�g���N�^</para>
///<para>���삷��item�̃|�C���^��ǉ��Ŏ󂯎��</para>
///<para>����:</para>
///<param name="item"><para>item:���삷��item�̃|�C���^</para></param>
///</summary>
ItemHit::ItemHit(Collision *collision,Item* item) : Hit(collision){
	item_ = item;
}

///<summary>
///<para>�ڐG����</para>
///<para>item_��state��ύX������A�����Ŏ󂯎����int�̐��l�ɂ����X����Y���Ɏ󂯎����float�̐��l�����Z����</para>
///<para>����:</para>
///<param name="check"><para>check:Collision::HitCheckX��Collision::HitCheckX�ACollision::MapCheck�̖߂�l�̈�ł���int�^�̐��l</para></param>
///<param name="distance"><para>distance:Collision::HitCheckX��Collision::HitCheckX�ACollision::MapCheck�̖߂�l�̈�ł���float�^�̐��l</para></param>
///</summary>
void ItemHit::HitObjects(int check,float distance) {
	item_->state_ = Item_Normal;
	switch (check) {
	case 1:
	case 2:
		item_->Set(item_->Left() + distance, item_->Top());
		break;
	case 3:
	case 4:
		item_->Set(item_->Left(), item_->Top() + distance);
		break;
	default:
		assert(false);
		break;
	}
}