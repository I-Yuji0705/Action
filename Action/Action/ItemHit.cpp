#include "ItemHit.h"
#include <assert.h>

ItemHit::ItemHit(Collision *collision,Item* item) : Hit(collision){
	item_ = item;
}

//----------
//ItemがObjectに当たった際の位置の調整とPlayerの状態を変更する
//引数：
//		check:int Check(float *point, float num,const Object *object)の返り値から、オブジェクトのどこに当たったかを求める
//		object:当ったオブジェクト
//void ItemHit::HitProcess(int hitcheck, Object* hitobject) {
//	item_->state_ = Item_Normal;
//	switch (hitcheck) {
//	case 1:
//		item_->x_ = hitobject->Left() - item_->width_;
//		break;
//	case 2:
//		item_->x_ = hitobject->Right();
//		break;
//	case 3:
//		item_->y_ = hitobject->Top() - item_->height_;
//		break;
//	case 4:
//		item_->y_ = hitobject->Base();
//		break;
//	default:
//		assert(false);
//		break;
//	}
//}
//Object* ItemHit::GetNearObject(Object* target, int hitcheck, std::vector<Object*> hitobjects) {
//	Object* hitobject;
//	for (auto i : hitobjects) {
//		if (i == *hitobjects.begin())hitobject == i;
//		else
//		{
//			switch (hitcheck) {
//			case 1:
//				if (i->Left() - item_->Right() < hitobject->Left() - item_->Right())
//					hitobject = i;
//				break;
//			case 2:
//				if (item_->Left() - i->Right() < item_->Left() - hitobject->Right())
//					hitobject = i;
//				break;
//			case 3:
//				if (item_->Base() - i->Top() < item_->Base() - hitobject->Top())
//					hitobject = i;
//				break;
//			case 4:
//				if (i->Base() - item_->Top() < hitobject->Base() - item_->Top())
//					hitobject = i;
//				break;
//			default:
//				assert(false);
//				break;
//			}
//		}
//	}
//	return hitobject;
//}
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