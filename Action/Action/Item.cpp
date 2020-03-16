#include "Item.h"
#include "Terrain.h"
#include <typeinfo.h>
#include <assert.h>
#include <tuple>
#include "DxLib.h"
#include "ItemBaggage.h"
#include "ItemGravity.h"
#include "ItemPutted.h"
#include "ItemThrew.h"
#include "ItemStartThrow.h"

///<summary>
///<para>�R���X�g���N�^</para>
///<para>�`�ʂ���摜�̐ݒ�A����������̏������s���N���X�A�s�����Ǘ�����N���X�̐���</para>
///<para>����:</para>
///<param name= "sound"><para>���쎞�ɉ��𔭐�������N���X</para></param>
///<param name= "collision"><para>���쎞�⓮��m�F���ɐڐG����𒲂ׂ�</para></param>
///</summary>
Item::Item(Sound* sound,Collision* collision,float x, float y, float height, float width) : Object(x, y, height, width) {
	sound_ = sound;
	collision_ = collision;
	graph_handle_ = LoadGraph("Image/Item.png");
	quality_ = true;
	itemhit_ = new ItemHit(collision_,this);
	itemaction_[Item_Baggage] = new ItemBaggage(this);
	itemaction_[Item_StartThrow] = new ItemStartThrow(this);
	itemaction_[Item_Threw] = new ItemThrew(sound_, collision_, this,itemhit_);
	itemaction_[Item_Putted] = new ItemPutted(this);
	itemaction_[Item_Gravity] = new ItemGravity(sound_, collision_, this,itemhit_);
}

///<summary>
///<para>����������</para>
///<para>�����������Ă���Player�̃|�C���^��nullptr�ɂ���</para>
///</summary>
void Item::Initialize() {
	vector_ = 1;
	state_ = Item_Normal;
	carrier_ = nullptr;
}

///<summary>
///<para>�X�V����</para>
///<para>Item�̏�Ԃɂ���Ăōs���s����ς���</para>
///</summary>
void Item::Update() {
	switch (state_) {
	case Item_Normal:
		itemaction_[Item_Gravity]->Do();
		break;
	case Item_Picked:
		itemaction_[Item_Baggage]->Do();
		break;
	case Item_Throw:
		itemaction_[Item_Threw]->Do();
		break;
	default:
		assert(false);
		break;
	}
}

///<summary>
///<para>�`�ʏ���</para>
///<para>Item�̌����ɂ���āA�`�ʂ���摜�𔽓]����</para>
///</summary>
void Item::Draw() {
	if (vector_ == 1) DrawModiGraphF(x_, y_, x_ + width_, y_, x_ + width_, y_ + height_, x_, y_ + height_, graph_handle_, TRUE);
	else DrawModiGraphF(x_ + width_, y_, x_, y_, x_, y_ + height_, x_ + width_, y_ + height_, graph_handle_, TRUE);
}

///<summary>
///<para>Object�Ɏ�����邩��Ԃ�</para>
///<para>Object�̓���Ɏ��g��u�����Ƃ��ł��邩�𒲂ׁA�Ԃ�</para>
///<para>����:</para>
///<param name="object"><para>object:����������Object</para></param>
///<para>�߂�l:</para>
///<returns>
///<para>true:�����������Ƃ��ł���</para>
///<para>false:�����������Ƃ��ł��Ȃ�</para>
///</returns>
///</summary>
bool Item::CanPicked(const Object *object) {
	bool canpicked = true;
	if (collision_->Check(object->Center_X() - GetWidth() / 2, object->Top() - GetHeight(), this)) {
		canpicked = false;
	}
	return canpicked;
}

///<summary>
///<para>Object�Ɏ����ꂽ�n�߂�ۂ̏���</para>
///<para>������state��ύX���A�������Ώۂ��|�C���^�ɕۑ����A�����̈ʒu��ύX����</para>
///<para>����:</para>
///<param name="object"><para>object:����������Object</para></param>
///</summary>
void Item::Picked(Object *object) {
	state_ = Item_Picked;
	carrier_ = object;
	itemaction_[Item_Baggage]->Do();
}

///<summary>
///<para>carrier_�ɒu����邱�Ƃ��ł��邩��Ԃ�</para>
///<para>Object�̓���Ɏ��g��u�����Ƃ��ł��邩�𒲂ׁA�Ԃ�</para>
///<para>�߂�l:</para>
///<returns>
///<para>true:�����������Ƃ��ł���</para>
///<para>false:�����������Ƃ��ł��Ȃ�</para>
///</returns>
///</summary>
bool Item::CanPutted() {
	bool canputted = true;
	if (state_ != Item_Picked) {
		canputted = false;
	}
	else {
		float posx;
		float posy = carrier_->Base() - GetHeight();
		if (vector_ == 1) {
			posx = carrier_->Right();
		}
		else {
			posx = carrier_->Left() - GetWidth();
		}
		int mapcheck;
		float distance;
		std::tie(mapcheck, distance) = collision_->MapCheck(posx, this);
		if (collision_->Check(posx, posy, this) || mapcheck != 0) {
			canputted = false;
		}
	}
	return canputted;
}

///<summary>
///<para>Object�Ɏ����ꂽ�n�߂�ۂ̏���</para>
///<para>state�Ǝ������Ώۂ��|�C���^�ɕۑ����A�����̈ʒu��ύX����</para>
///<para>����:</para>
///<param name="object"><para>object:����������Object</para></param>
///</summary>
void Item::Putted() {
	itemaction_[Item_Putted]->Do();
}

///<summary>
///<para>carrier_�ɓ�������ہA������邩��Ԃ�</para>
///<para>Item��vector_���瓊����ۂɎ���������ʒu�ɑ���Object���Ȃ������ׂ�</para>
///<para>�߂�l:</para>
///<returns>
///<para>true:���������邱�Ƃ��ł���</para>
///<para>false:�����𓊂��邱�Ƃ��ł��Ȃ�</para>
///</returns>
///</summary>
bool Item::CanThrew() {
	bool canthrew = true;
	if (state_ != Item_Picked) {
		canthrew = false;
	}
	else {
		float posx;
		float posy = carrier_->Base() - GetHeight();
		if (vector_ == 1) {
			posx = carrier_->Right();
		}
		else {
			posx = carrier_->Left() - GetWidth();
		}
		int mapcheck;
		float distance;
		std::tie(mapcheck, distance) = collision_->MapCheck(posx, this);
		if (collision_->Check(posx, posy, this) || mapcheck != 0) {
			canthrew = false;
		}
	}
	return canthrew;
}

///<summary>
///<para>��������ۂ̏���</para>
///<para>�����̈ʒu��ύX����</para>
///</summary>
void Item::Threw() {
	itemaction_[Item_StartThrow]->Do();
}

///<summary>
///<para>���g���C����</para>
///<para>�����̈ʒu���ŏ��̈ʒu�ɖ߂��A�������������s��</para>
///</summary>
void Item::Retry() {
	Object::Retry();
	Initialize();
}

///<summary>
///<para>������悤�Ƃ��Ă��鐔������A������������邱�Ƃ̂ł��鐔����Ԃ�</para>
///<para>�X�e�[�W�[�Ɉړ����Ă��܂��ꍇ�A���̍��̐�����Ԃ�</para>
///<para>������������镪�����𔼕��ɂ�����A�ړ����Object���������ꍇ����Object��Capushed���ċA�����A��ԏ�����������Ԃ�</para>
///<para>����:</para>
///<param name="num"><para>num:���݂̈ʒu���瓮�������Ƃ��Ă�����W�ւ̍�</para></param>
///<para>�߂�l:</para>
///<returns>
///<para>num�ɑ΂��āA���ۂɂ���Object�𓮂����鋗��</para>
///</returns>
///</summary>
float Item::CanPushed(float num) {
	float canpushed = num / 2;
	int hitpoint;
	float distance;
	std::vector<Object*> hitobject;
	std::tie(hitpoint, distance) = collision_->MapCheck(Left() + num / 2, this);
	if (hitpoint != 0) {
		canpushed = distance;
	}
	else {
		std::tie(hitpoint, distance, hitobject) = collision_->HitCheckX(num / 2, this);
		if (hitpoint != 0 ){
			if (distance != 0.0f) {
				canpushed = distance;
			}else if(!hitobject.empty()) {
				for (auto i : hitobject) {
					if (std::abs(canpushed) > std::abs(i->CanPushed(num / 2))) {
						canpushed = i->CanPushed(num / 2);
					}
				}
			}
		}
	}
	return canpushed;
}

///<summary>
///<para>�����Ŏ󂯎�������������W���ړ�����</para>
///<para>�ړ���ɑ���Object���������ꍇ�A����Object��Pushed���g���A�ċA������</para>
///<para>����:</para>
///<param name="num"><para>num:���݂̈ʒu���瓮�������Ƃ��Ă�����W�ւ̍�</para></param>
///</summary>
void Item::Pushed(float num) {
	int hitpoint;
	float distance;
	std::vector<Object*> hitobject;
	std::tie(hitpoint, distance, hitobject) = collision_->HitCheckX(num, this);
	if (hitpoint != 0 && !hitobject.empty()) {
		for (auto i : hitobject) {
			i->Pushed(num);
		}
	}
	Set(Left() + num, Top());
}
