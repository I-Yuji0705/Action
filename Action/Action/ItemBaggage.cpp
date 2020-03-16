#include "ItemBaggage.h"

///<summary>
///<para>�R���X�g���N�^</para>
///</summary>
ItemBaggage::ItemBaggage(Item *item) : ItemAction(item) {
}

///<summary>
///<para>�s������</para>
///<para>carrier_�̓���ɗ���悤�Ɉʒu��ύX���A�����������ɂȂ�l�ɍX�V����</para>
///</summary>
void ItemBaggage::Do() {
	item_->Set(item_->carrier_->Center_X() - item_->GetWidth() / 2, item_->carrier_->Top() - item_->GetHeight());
	item_->vector_ = item_->carrier_->vector_;
}