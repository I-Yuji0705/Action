#include "ClearZone.h"
#include <typeinfo.h>
#include "DxLib.h"
//�N���A�����ۂɁAClearZone�̎��ӂɃN���A�����ۂ̉��o�̒ǉ�
bool ClearZone::ClearCheck() {
	bool check = true;
	const int permissibleLength = 5;//��������ĂĂ����v�Ȓ���
	for (int i = (int)this->Left() + permissibleLength; i < (int)this->Right() - permissibleLength; i++) {
		for (int j =(int)this->Top() + permissibleLength; j < (int)this->Base() - permissibleLength; j++) {
			if (ZoneCheck_Y((float)i, (float)j) == 0) {
				check = false;
				break;
			}
			else {
				j += ZoneCheck_Y((float)i, (float)j);
			}
		}
	}
	return check;
}
bool ClearZone::ZoneCheck(float x, float y) {
	bool check = false;
	for (auto i : (*stage_)) {
		if (i->Left() <= x && x <= i->Right() &&
			i->Top() <= y && y <= i->Base()) {
			check = true;
			break;
		}
	}
	return check;
}
//-------------
//�I�����������̍��W�n�_��Object�����邩�ǂ����A�������ꍇ��y���W����ǂ̒��x�̍�������Ԃ�
//	����::x-->���W��x�n�_
//		  y-->���W��y�n�_
//	�Ԃ�l::0-->Object�͑��݂��Ȃ������B
//		0�ȊO-->������y������W�n�_�ɂ�����Object�̒�ӂ܂ł̒���
int ClearZone::ZoneCheck_Y(float x, float y) {
	bool check = false;
	int length_y = 0;
	Object* object = nullptr;
	for (auto i : (*stage_)) {
		if (i != this && 
			i->Left() <= x && x <= i->Right() &&
			i->Top() <= y && y <= i->Base()) {
			check = true;
			object = i;
			break;
		}
	}
	if (check) {
		length_y = (int)(object->Base() - y);
	}
	return length_y;
}
void ClearZone::Clear() {
	
}
ClearZone::ClearZone(float x, float y, float height, float width, int object_number) : Object(x, y, height, width, object_number) {
	quality_ = false;
	switch (object_number_) {
	case 0:
		break;
	default:
		break;
	}
}

void ClearZone::Initialize(IStateChanger *stateChanger, std::vector<Object*>& stage) {
	Object::Initialize(stateChanger, stage);
	for (int i = 0; i != (*stage_).size(); i++) {
		if (typeid(*stage[i]) == typeid(Player)) {
			player_ = stage[i];
		}
	}
}
void ClearZone::Update() {
	if (ClearCheck() && player_->CanClear()) {
		player_->Clear();
	}
}
void ClearZone::Draw() {
	DrawBoxAA(x_, y_, x_ + width_, y_ + height_, GetColor(60, 128, 106), TRUE);//Float�^�̎l�_�̍��W����O�g��`��
}