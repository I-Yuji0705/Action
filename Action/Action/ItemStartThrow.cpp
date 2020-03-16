#include "ItemStartThrow.h"

///<summary>
///<para>�R���X�g���N�^</para>
///</summary>
ItemStartThrow::ItemStartThrow(Item *item) : ItemAction(item) {
}

///<summary>
///<para>�s������</para>
///<para>carrier_�̌������瓊�����n�߂�ꏊ�����߁Aitem_�̈ʒu�𓊂����n�߂�ꏊ�ɕύX����</para>
///<para>tem_��state��ς��Acarrier_��nullptr�ɕς���</para>
///</summary>
void ItemStartThrow::Do() {
	float posx;
	float posy = item_->carrier_->Base() - item_->GetHeight();
	if (item_->vector_ == 1) {
		posx = item_->carrier_->Right();
	}
	else {
		posx = item_->carrier_->Left() - item_->GetWidth();
	}
	item_->Set(posx, posy);
	item_->state_ = Item_Throw;
	item_->carrier_ = nullptr;
}