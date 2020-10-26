#include "ItemPutted.h"

///<summary>
///<para>�R���X�g���N�^</para>
///</summary>
ItemPutted::ItemPutted(Item *item) : ItemAction(item) {
}

///<summary>
///<para>�s������</para>
///<para>carrier_�̌�������u���ꏊ�����߁Aitem_�̈ʒu��u���ꏊ�ɕύX����</para>
///<para>item_��state��ʏ펞�ɕς��Acarrier_��nullptr�ɕς���</para>
///</summary>
void ItemPutted::Do() {
	float posx;
	float posy = item_->carrier_->Base() - item_->GetHeight();
	if (item_->carrier_->vector_ == 1) {
		posx = item_->carrier_->Right();
	}
	else {
		posx = item_->carrier_->Left() - item_->GetWidth();
	}
	item_->Set(posx, posy);
	item_->state_ = ItemState::Item_Normal;
	item_->carrier_ = nullptr;
}