#include "Collision.h"
#include <vector>
#include <typeinfo>
#include <cassert>
#include "Player.h"

///<summary>
///Stage�̃|�C���^�̎���
///</summary>
Collision::Collision(std::vector<Object*>* stage) {
	stage_ = stage;
}


///<summary>
///<para>����������</para>
///<para>Stage�̃|�C���^����A�X�e�[�W�E�[�ƍ��[��Terrain�̎���</para>
///</summary>
void Collision::Initialize() {
	map_left_, map_right_ = nullptr;
	for (auto i : *stage_) {
		if (typeid(*i) == typeid(Terrain)) {
			if (map_left_ == nullptr) map_left_ = i;
			else if (map_left_->Left() > i->Left()) map_left_ = i;
			if (map_right_ == nullptr) map_right_ = i;
			else if (map_right_->Right() < i->Right()) map_right_ = i;
		}
	}
}

///<summary>
///<para>
///�Ώۂ̃I�u�W�F�N�g���w�肵�����W��ɏo��ꍇ�A�w�肵��Object�ɐڐG���邩��Ԃ�
///</para>
///<param name="x"><para>x:�Ώۂ�Object���ړ�����X���W</para></param>
///<param name="y"><para>y:�Ώۂ�Object���ړ�����Y���W</para></param>
///<param name="player"><para>player:�Ώۂ�Object�̃|�C���^</para></param>
///<param name="object"><para>object:���ׂ�Object�̃|�C���^</para></param>
///<returns>
///<para>true:Object���ڐG����</para>
///<para>false:Object���ڐG���Ȃ�</para>
///</returns>
///</summary>
bool Collision::Check(float x, float y,const Object* player, const Object* object) {
	bool check = false;
	if (Check(x,y,x + player->GetWidth(), y + player->GetHeight(),object))
		check = true;
	return check;
}

///<summary>
///<para>
///�w�肵���E��̍��W�ƍ����̍��W��Ίp���Ƃ���l�p�`�̒��ɁA�w�肵��Object���ڐG���Ă��邩��Ԃ�
///</para>
///<param name="x1"><para>x1:���ׂ�͈͂̍����X���W</para></param>
///<param name="y1"><para>y1:���ׂ�͈͂̍����Y���W</para></param>
///<param name="x2"><para>x2:���ׂ�͈͂̉E����X���W</para></param>
///<param name="y2"><para>y2:���ׂ�͈͂̉E����Y���W</para></param>
///<param name="object"><para>object:�Ώۂ�Object�̃|�C���^</para></param>
///<returns>
///<para>true:Object���ڐG����</para>
///<para>false:Object���ڐG���Ȃ�</para>
///</returns>
///</summary>
bool Collision::Check(float x1, float y1, float x2, float y2,
	const Object* object) {
	bool check = false;
	if (object->quality_ && 
		y1  < object->Base() && object->Top() < y2 &&
		x1 < object->Right() && object->Left() < x2)
		check = true;
	return check;
}

///<summary>
///<para>�ڐG�����̃I�u�W�F�N�g���ڐG����܂ňړ�����Object�������鐔�l</para>
///<param name="target"><para>target:player���ڐG����Object�̃|�C���^</para></param>
///<param name="player"><para>player:�ړ�����Object�̃|�C���^</para></param>
///<param name="check"><para>check:HitCheckX�܂���HitCheckY����check�ϐ�</para></param>
///<returns>
///<para>��̃I�u�W�F�N�g���ڐG����܂�player�������鐔�l</para>
///</returns>
///</summary>
float Collision::ObjectDistance(const Object* target, const Object* player, int check) {
	float distance;
	switch (check)
	{
	case 1://object�̍����ɐڐG
		distance = target->Left() - player->Right();
		break;
	case 2://object�̉E���ɐڐG
		distance = target->Right() - player->Left();
		break;
	case 3://object�̏㑤�ɐڐG
		distance = target->Top() - player->Base();
		break;
	case 4://object�̉����ɐڐG
		distance = target->Base() - player->Top();
		break;
	default:
		assert(false);
		break;
	}
	return distance;
}

///<summary>
///<para>�Ώۂ�Object����ʒ[�܂ŐڐG����܂œ����鐔�l��Ԃ�</para>
///<param name="player"><para>player:�ړ�����Object�̃|�C���^</para></param>
///<param name="check"><para>check:MapCheck����check�ϐ�</para></param>
///<returns>
///<para>Object���X�e�[�W���[�܂��͉E�[�܂ɐڐG����܂œ����鐔�l</para>
///</returns>
///</summary>
float Collision::MapDistance(const Object* player, int check) {
	float distance;
	switch (check) {
	case 1://�X�e�[�W�̉E�[�ɐڐG����
		distance = map_right_->Right() - player->Right();
		break;
	case 2://�X�e�[�W�̍��[�ɐڐG����
		distance =map_left_->Left() - player->Left();
		break;
	default:
		assert(false);
		break;
	}
	return distance;
}

///<summary>
///<para>
///�Ώۂ̃I�u�W�F�N�g���w�肵�����W��ɏo��ꍇ�A�w�肵��Object�ɐڐG���邩��Ԃ�
///</para>
///<param name="x"><para>x:�Ώۂ�Object���ړ�����X���W</para></param>
///<param name="y"><para>y:�Ώۂ�Object���ړ�����Y���W</para></param>
///<param name="player"><para>player:�Ώۂ�Object�̃|�C���^</para></param>
///<returns>
///<para>true:Object���ڐG����</para>
///<para>false:Object���ڐG���Ȃ�</para>
///</returns>
///</summary>
bool Collision::Check(float x, float y, const Object* player) {
	bool check = false; 
	for (auto i : *stage_) {
		if (i != player && i->quality_ &&
			Check(x , y , player, i)) {
			check = true;
			break;
		}
	}
	return check;
}

///<summary>
///<para>�w�肵��X�n�_�Ɉړ������ꍇ�A�X�e�[�W�̊O�ɏo�邩�ǂ����A</para>
///<para>�o��ꍇ�A���݂̈ʒu����ڐG����܂œ����鐔�l��Ԃ�</para>
///<param name="num"><para>num:�ړ����悤�Ƃ��Ă���X�n�_</para></param>
///<param name="player"><para>player:�ړ�����Object�̃|�C���^</para></param>
///<returns>
///<para>int:Object���X�e�[�W���[�܂��͉E�[�ɐڐG���邩</para>
///<para>0:�ڐG���Ȃ�</para>
///<para>1:�E�[�ɐڐG����</para>
///<para>2:���[�ɐڐG����</para>
///<para>float:�ڐG����ꍇ�A�ڐG����܂œ����鐔�l</para>
///<para>999.0f:�ڐG���Ȃ�</para>
///<para>999.0f�ȊO:�ڐG����܂œ����鐔�l</para>
///</returns>
///</summary>
std::tuple<int,float> Collision::MapCheck(float num,const Object* player) {
	int check = 0;
	float distance = 999.0f;
	if (num + player->GetWidth() > map_right_->Right()) check = 1;
	else if (num < map_left_->Left()) check = 2;
	if(check != 0)distance = MapDistance(player, check);
	return std::forward_as_tuple(check, distance);
}

///<summary>
///<para>�����̍��W�n�_��Object�����邩�ǂ����A�������ꍇ��y���W����ǂ̒��x�̍�������Ԃ�</para>
///<para>�������ꍇ��y���W����ǂ̒��x�̍�������Ԃ�</para>
///<param name="x"><para>x:���ׂ���W��X���W</para></param>
///<param name="y"><para>y:���ׂ���W��Y���W</para></param>
///<param name="player"><para>player:�ړ�����Object�̃|�C���^</para></param>
///<returns>
///<para>Object�����݂����ꍇ�Ay����ǂ̒��x�̍�����</para>
///<para>0:�ڐG����Object�����݂��Ȃ�����</para>
///<para>0�ȊO:�ڐG����Object��y�n�_����̍���</para>
///</returns>
///</summary>
int Collision::PointCheck(float x, float y,const Object *player) {
	int length_y = 0;
	Object* object = nullptr;
	for (auto i : *stage_) {
		if (i != player && i->quality_ && 
			i->Left() <= x && x <= i->Right() &&
			i->Top() <= y && y <= i->Base()) {
			object = i;//��������������Object���Z�b�g
			break;
		}
	}
	if (object != nullptr) {
		length_y = (int)(object->Base() - y);//y�n�_����Object�̒�ӂ܂ł̋���
	}
	return length_y;
}

///<summary>
///<para>�I������Object�̓������ׂĂɑ���Object�����݂��邩��Ԃ��֐�</para>
///<param name="area"><para>area:���ׂ�Ώ�Object�̃|�C���^</para></param>
///<returns>
///<para>true:area�����S�Ă�����Ojbect�Ŗ�������Ă���</para>
///<para>false:area�����S�Ă�����Ojbect�Ŗ�������Ă��Ȃ�</para>
///</returns>
///</summary>
bool Collision::AreaFullCheck(const Object* area) {
	bool check = true;
	const int kPermissibleLength = 10;//�����O�����炸��ĂĂ����v�Ȓ���
	const int kPermissibleGap = 1;//�G���A�����ŋ󂢂ĂĂ����v�Ȍ��Ԃ̑傫��
	int gap = 0;
	for (int i = (int)area->Left() + kPermissibleLength; i < (int)area->Right() - kPermissibleLength; i++) {
		for (int j = (int)area->Top() + kPermissibleLength; j < (int)area->Base() - kPermissibleLength; j++) {
			if (PointCheck((float)i, (float)j, area) == 0) {
				if (gap >= kPermissibleGap) {
					check = false;
					break;
				}
				else
					gap++;
			}
			else {
				j += PointCheck((float)i, (float)j, area);
				gap = 0;
			}
		}
	}
	return check;
}

///<summary>
///<para>�w�肵���E��̍��W�ƍ����̍��W��Ίp���Ƃ���l�p�`�̒��ɑ��݂��鑼��Object���Ԃ�</para>
///<param name="target"><para>target:�߂�l�̊i�[��</para></param>
///<param name="x1"><para>x1:���ׂ�͈͂̍����X���W</para></param>
///<param name="y1"><para>y1:���ׂ�͈͂̍����Y���W</para></param>
///<param name="x2"><para>x2:���ׂ�͈͂̉E����X���W</para></param>
///<param name="y2"><para>y2:���ׂ�͈͂̉E����Y���W</para></param>
///<param name="player"><para>player:��₩��O��Object�̃|�C���^</para></param>
///<returns>
///<para>nullptr:</para>
///<para>�w�肵���͈͓���Object�����݂��Ȃ�</para>
///<para>nullptr�ȊO:</para>
///<para>�w�肵���͈͂̒��ɂɑ��݂��A</para>
///<para>player�ɋ߂�����Object�̃|�C���^</para>
///</returns>
///</summary>
Object* Collision::AreaCheck(Object* target, float x1, float y1, float x2, float y2, const Object* player) {
	target = nullptr;
	for (auto i : *stage_) {//�X�e�[�W��̃I�u�W�F�N�g���猟��
		if (i != player && Check(x1,y1,x2,y2,i) &&//
			(target == nullptr ||
				abs(player->Center_X() - i->Center_X()) <= abs(player->Center_X() - target->Center_X()) &&
				(i->Base() < target->Base()))) {
			target = i;//�����グ��Ώۂ�ݒ肷��
		}
	}
	return target;
}

///<summary>�X�e�[�W�̍��[�ɂ���n�`��Ԃ�
///<param name="target">target:�߂�l�̊i�[��</param>
///<returns>
///<para>�X�e�[�W�E�[��Terrain�̃|�C���^</para>
///</returns>
///</summary>
Object* Collision::GetMapLeft(Object* target) {
	target = map_left_;
	return target;
}

///<summary>�X�e�[�W�̍��[�ɂ���n�`��Ԃ�
///<param name="target"><para>target:�߂�l�̊i�[��</para></param>
///<returns>
///<para>�X�e�[�W�E�[��Terrain�̃|�C���^</para>
///</returns>
///</summary>
Object* Collision::GetMapRight(Object* target) {
	target = map_right_;
	return target;
}

///<summary>�X�e�[�W��ɂ���Player�S�Ă�Ԃ�
///<returns>
///<para>�X�e�[�W��ɂ���Player�S��</para>
///</returns>
///</summary>
std::vector<Object*> Collision::GetPlayer() {
	std::vector<Object*> players;
	for (auto i: *stage_) {
		if (typeid(*i) == typeid(Player)) {
			players.push_back(i);
		}
	}
	return players;
}

///<summary>
///<para>�Ώۂ�Object��X���ɐ��l��ǉ��������ʁA����Object�ɐڐG���邩�A</para>
///<para>�����ꍇ�ɂ͂ǂ̕����ɐڐG�������A�ڐG����Object�A</para>
///<para>�ڐG����Object�̂����A��ԋ߂�Object�ƐڐG����܂őΏۂ�Object�������鐔�l��Ԃ�</para>
///<param name="num"><para>num:�Ώۂ�Object��Y���W�ɒǉ�����\��̐��l</para></param>
///<param name="player"><para>player:�Ώۂ�Object�̃|�C���^</para></param>
///<returns>
///<para>int:Object�ɐڐG�������A�����ꍇ�͂ǂ̕����ɐڐG������</para>
///<para>0:�ڐG���Ȃ�</para>
///<para>1:object�̍����ɐڐG</para>
///<para>2:object�̉E���ɐڐG</para>
///<para>float:num�ɑ΂��āA���ۂ�player��X���ɒǉ��ł���l</para>
///<para>std::vector:�ڐG�����S�Ă�Object�̃|�C���^</para>
///</returns>
///</summary>
std::tuple<int,float, std::vector<Object *>> 
	Collision::HitCheckX(float num, const Object* player) {
	int check = 0;
	float distance = 999.0f;//999.0f:�����l
	std::vector<Object*> hitobjects;
	for (auto i : *stage_) {
		if (i != player && i->quality_ &&
			Check(player->Left() + num, player->Top(), player, i)) {
			hitobjects.push_back(i);
			if (num > 0) check = 1;//�n�`�̏㑤����Փ˂�����
			else check = 2;//�n�`�̉�����Փ˂�����
			if (check != 0 && std::abs(distance) > std::abs(ObjectDistance(i, player, check)))
				distance = ObjectDistance(i, player, check);
		}
	}
	return std::forward_as_tuple(check, distance, hitobjects);
}


///<summary>
///<para>�Ώۂ�Object��Y���ɐ��l��ǉ��������ʁA����Object�ɐڐG���邩�A</para>
///<para>�����ꍇ�ɂ͂ǂ̕����ɐڐG�������A�ڐG����Object�A</para>
///<para>�ڐG����Object�̂����A��ԋ߂�Object�ƐڐG����܂őΏۂ�Object�������鐔�l��Ԃ�</para>
///<param name="num"><para>num:�Ώۂ�Object��Y���W�ɒǉ�����\��̐��l</para></param>
///<param name="player"><para>player:�Ώۂ�Object�̃|�C���^</para></param>
///<returns>
///<para>int:Object�ɐڐG�������A�����ꍇ�͂ǂ̕����ɐڐG������</para>
///<para>0:�ڐG���Ȃ�</para>
///<para>3:object�̏㑤�ɐڐG</para>
///<para>4:object�̉����ɐڐG</para>
///<para>float:num�ɑ΂��āA���ۂ�player��Y���ɒǉ��ł���l</para>
///<para>std::vector:�ڐG�����S�Ă�Object�̃|�C���^</para>
///</returns>
///</summary>
std::tuple<int, float, std::vector<Object *>>
Collision::HitCheckY(float num, const Object* player) {
	int check = 0;
	float distance = 999.0f;//999.0f:�����l
	std::vector<Object*> hitobjects;
	for (auto i : *stage_) {
		if (i != player && i->quality_ &&
			Check(player->Left(), player->Top() + num, player, i)) {
			hitobjects.push_back(i);
			if (num > 0) check = 3;//�n�`�̏㑤����Փ˂�����
			else check = 4;//�n�`�̉�����Փ˂�����
			if (check != 0 && std::abs(distance) > std::abs(ObjectDistance(i, player, check)))
				distance = ObjectDistance(i, player, check);
		}
	}
	return std::forward_as_tuple(check, distance, hitobjects);
}