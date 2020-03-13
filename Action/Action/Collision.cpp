#include "Collision.h"
#include <vector>
#include <typeinfo>
#include "Player.h"

//Stage�ƁA�E�[�̒n�`�ƍ��[�̒n�`�̏K��
Collision::Collision(std::vector<Object*> stage) {
	stage_ = stage;
	//�X�e�[�W�[�ɂ���n�`�̌���
	map_left_, map_right_ = nullptr;
	for (auto i : stage_) {
		if (typeid(*i) == typeid(Terrain)) {
			if (map_left_ == nullptr) map_left_ = i;
			else if (map_left_->Left() > i->Left()) map_left_ = i;
			if (map_right_ == nullptr) map_right_ = i;
			else if (map_right_->Right() < i->Right()) map_right_ = i;
		}
	}
}

//�Ώۂ̃I�u�W�F�N�g���w�肵�����W��ɏo��ꍇ�A
//�w�肵��Object�ɐڐG���邩��Ԃ�
//����:
//		x:�Ώۂ�Object���ړ�����X���W
//		y:�Ώۂ�Object���ړ�����Y���W
//		player:�Ώۂ�Object
//		object:���ׂ�Object
//�Ԃ�l:
//		true:Object���ڐG����
//		false:Object���ڐG���Ȃ�
bool Collision::Check(float x, float y,const Object* player, const Object* object) {
	bool check = false;
	if (Check(x,y,x + player->GetWidth(), y + player->GetHeight(),player,object))
		check = true;
	return check;
}

bool Collision::Check(float x1, float y1, float x2, float y2,
	const Object* player,const Object* object) {
	bool check = false;
	if (object->quality_ && object != player &&
		y1  < object->Base() && object->Top() < y2 &&
		x1 < object->Right() && object->Left() < x2)
		check = true;
	return check;
}
//�Ώۂ̃I�u�W�F�N�g���w�肵�����W��ɏo��ꍇ�A
//�ڐG����Object�����݂��邩�ǂ����Ԃ�
//����:
//		x:�Ώۂ�Object���ړ�����X���W
//		y:�Ώۂ�Object���ړ�����Y���W
//		player:�Ώۂ�Object
//�Ԃ�l:
//		true:Object���ڐG����
//		false:Object���ڐG���Ȃ�
bool Collision::Check(float x, float y, const Object* player) {
	bool check = false; 
	for (auto i : stage_) {
		if (i != player && i->quality_ &&
			Check(x , y , player, i)) {
			check = true;
			break;
		}
	}
	return check;
}
//Object��num�n�_�Ɉړ������ꍇ�A�X�e�[�W�̊O�ɏo�邩�ǂ�����Ԃ�
//����:
//		num:object�̈ړ��n�_
//		object:������s��Object
//�Ԃ�l:
//		0:�X�e�[�W�̊O�ɂ͏o�Ȃ�
//		1:�X�e�[�W�̉E������O�ɏo��
//		2:�X�e�[�W�̍�������O�ɏo��
int Collision::MapCheck(float num,const Object* player) {
	int check = 0;
	if (num + player->GetWidth() > map_right_->Right()) check = 1;
	else if (num < map_left_->Left()) check = 2;
	return check;
}
//-------------
//�I�����������̍��W�n�_��Object�����邩�ǂ����A�������ꍇ��y���W����ǂ̒��x�̍�������Ԃ�
//	����:
//		x:���W��x�n�_
//		y:���W��y�n�_
//		player:�����̑ΏۊO�ɂ���Object
//	�Ԃ�l:
//		0:Object�͑��݂��Ȃ������B
//		0�ȊO:������y������W�n�_�ɂ�����Object�̒�ӂ܂ł̒���
int Collision::PointCheck(float x, float y,const Object *player) {
	int length_y = 0;
	Object* object = nullptr;
	for (auto i : stage_) {
		if (i != player &&
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

//-------------
//�I������Object�̓������ׂĂɑ���Object�����݂��邩��Ԃ��֐�
//	����:
//		area:���ׂ�Object
//	�Ԃ�l:
//		true:area�����̂قڑS�ĂɃI�u�W�F�N�g�����݂���
//		false:area�����ɃI�u�W�F�N�g�����݂��Ă��Ȃ����Ԃ�������
bool Collision::AreaFullCheck(const Object* area) {
	bool check = true;
	const int permissibleLength = 5;//�����O�����炸��ĂĂ����v�Ȓ���
	for (int i = (int)area->Left() + permissibleLength; i < (int)area->Right() - permissibleLength; i++) {
		for (int j = (int)area->Top() + permissibleLength; j < (int)area->Base() - permissibleLength; j++) {
			if (PointCheck((float)i, (float)j, area) == 0) {
				check = false;
				break;
			}
			else {
				j += PointCheck((float)i, (float)j, area);
			}
		}
	}
	return check;
}
//-------------
//�I�������͈͓��ɑ���Object�����݂��邩��Ԃ��֐�
//	����:
//		target:���ʂ��i�[����Object
//		x1:�͈͓��̉E���X���W
//		y1:�͈͓��̉E���Y���W
//		x2:�͈͓��̍�����X���W
//		y2:�͈͓��̍�����Y���W
//		player:�����̑ΏۊO�ɂ���Object
//	�Ԃ�l:
//		nullptr:�ڐG����Object�͖���
//		nullptr�ȊO:�ڐG����Object�̃|�C���^
Object* Collision::AreaCheck(Object* target, float x1, float y1, float x2, float y2, const Object* player) {
	target = nullptr;
	for (auto i : stage_) {//�X�e�[�W��̃I�u�W�F�N�g���猟��
		if (Check(x1,y1,x2,y2,player,i) &&//
			(target == nullptr ||
				abs(player->x_ - i->x_) <= abs(player->x_ - target->x_) &&
				//(abs(player->x_ - i->x_) == abs(player->x_ - target->x_) &&
				(i->Base() < target->Base()))) {
			target = i;//�����グ��Ώۂ�ݒ肷��
		}
	}
	return target;
}

//-------------
//�X�e�[�W�̍��[�ɂ���n�`��Ԃ�
//	����:
//		target:���ʂ��i�[����Object
//	�Ԃ�l:
//		�X�e�[�W�̍��[�ɂ���n�`��Ԃ�
Object* Collision::GetMapLeft(Object* target) {
	target = map_left_;
	return target;
}

//-------------
//�X�e�[�W�̉E�[�ɂ���n�`��Ԃ�
//	����:
//		target:���ʂ��i�[����Object
//	�Ԃ�l:
//		�X�e�[�W�̍��[�ɂ���n�`��Ԃ�
Object* Collision::GetMapRight(Object* target) {
	target = map_right_;
	return target;
}

//-------------
//�X�e�[�W��ɂ���Player�S�Ă�Ԃ�
//	�Ԃ�l:
//		�X�e�[�W��ɂ���Player�S�Ă�Ԃ�
std::vector<Object*> Collision::GetPlayer() {
	std::vector<Object*> players;
	for (auto i: stage_) {
		if (typeid(*i) == typeid(Player)) {
			players.push_back(i);
		}
	}
	return players;
}
//Player��X����num��ǉ��������ʁAobject�ɐڐG���邩�A�����ꍇ�ɂ͂ǂ̕����ɐڐG��������Ԃ�
//����:
//		num:X���ɉ��Z���鐔��(�ړ����鋗��)
//		object:�ڐG���邩������s��Object
//�Ԃ�l:
//	int:
//		0:�ڐG�Ȃ�
//		1:object�̍����ɐڐG
//		2:object�̉E���ɐڐG
//	Object*:
//		nullptr:�ڐG����Object�͖���
//		nullptr�ȊO:�ڐG����Object�̃|�C���^
std::tuple<int, std::vector<Object *>> Collision::HitCheckX(float num, const Object* player) {
	int check = 0;
	std::vector<Object*> hitobject;
	for (auto i : stage_) {
		if (i != player && i->quality_ &&
			Check(player->Left() + num, player->Top(), player, i)) {
			hitobject.push_back(i);
			if (num > 0) check = 1;//�n�`�̏㑤����Փ˂�����
			else check = 2;//�n�`�̉�����Փ˂�����
		}
	}
	return std::forward_as_tuple(check, hitobject);
}
//Player��X����num��ǉ��������ʁAobject�ɐڐG���邩�A�����ꍇ�ɂ͂ǂ̕����ɐڐG��������Ԃ�
//����:
//		num:Y���ɉ��Z���鐔��(�ړ����鋗��)
//		object:�ڐG���邩������s��Object
//�Ԃ�l:
//	int:
//		0:�ڐG�Ȃ�
//		3:object�̏㑤�ɐڐG
//		4:object�̉����ɐڐG
//	Object*:
//		nullptr:�ڐG����Object�͖���
//		nullptr�ȊO:�ڐG����Object�̃|�C���^
std::tuple<int, std::vector<Object *>> Collision::HitCheckY(float num, const Object* player) {
	int check = 0;
	std::vector<Object*> hitobject;
	for (auto i : stage_) {
		if (i != player && i->quality_ &&
			Check(player->Left(), player->Top() + num, player, i)) {
			hitobject.push_back(i);
			if (num > 0) check = 3;//�n�`�̏㑤����Փ˂�����
			else check = 4;//�n�`�̉�����Փ˂�����
			break;
		}
	}
	return std::forward_as_tuple(check, hitobject);
}