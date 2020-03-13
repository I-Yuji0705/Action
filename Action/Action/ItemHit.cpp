#include "ItemHit.h"
#include <assert.h>

ItemHit::ItemHit(Collision *collision,Item* item) : Hit(collision){
	item_ = item;
}

//----------
//Item��Object�ɓ��������ۂ̈ʒu�̒�����Player�̏�Ԃ�ύX����
//�����F
//		check:int Check(float *point, float num,const Object *object)�̕Ԃ�l����A�I�u�W�F�N�g�̂ǂ��ɓ��������������߂�
//		object:�������I�u�W�F�N�g
void ItemHit::HitProcess(int hitcheck, Object* hitobject) {
	item_->state_ = Item_Normal;
	switch (hitcheck) {
	case 1:
		item_->x_ = hitobject->Left() - item_->width_;
		break;
	case 2:
		item_->x_ = hitobject->Right();
		break;
	case 3:
		item_->y_ = hitobject->Top() - item_->height_;
		break;
	case 4:
		item_->y_ = hitobject->Base();
		break;
	default:
		assert(false);
		break;
	}
}
void ItemHit::MapHit(int mapcheck) {
	item_->state_ = Item_Normal;
	switch (mapcheck) {
	case 1:
		item_->x_ = map_right_->Right() - item_->width_;
		break;
	case 2:
		item_->x_ = map_left_->Left();
		break;
	default:
		assert(false);
		break;
	}
}