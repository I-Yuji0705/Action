#include "Player.h"
#include <math.h>
#include <typeinfo.h>
#include <cstdlib>
#include "DxLib.h"
#include "Keyboard.h"
#include "Terrain.h"
#include "Item.h"

//�ۑ�_�FItem�������Ă����ԂŃW�����v���A�V��ɂԂ���ƁAItem�������Ă��Ȃ��ꍇ�Ɣ�r���đ؋󎞊Ԃ������Ȃ�
//			(Item�̈ʒu�X�V��Player�̈ړ��y��Carryon�̐ڐG������x��Ă��邽��)
//�Ή��@����1�FCheck�̈���num��gravity�̒l�����Z���Ĕ�����s���A���_�F��̊֐��ɓ����l�̒萔���g�p���邱�ƂɂȂ�B
//		����2�FCarryon��Check���s���O��Carryon��Update���s���A���_�FPlayer�̏�Ƀs�b�^���Ə��悤�ɂȂ�A�X�V�̂���ɂ��"�����Ă��銴"�������Ȃ鋰�ꂠ��B
//		����3�FItem���Ŕ�����s�킸�APlayer����Carryon��height��width�����ɓ����蔻��̌v�Z���s���A���_�Fwidth��height��private�ɂ��邱�Ƃ��s�\�ɂȂ�B
//�ۑ�_:Item�̉�����Player�����傫����ԂŁA�����Ă�Item�Ɉ����������Ă���Ƃ��̋�������

Player::Player(float x, float y, float height, float width, int object_number) : Object(x, y, height, width, object_number) {
	switch (this->object_number_) {
	case 0:
		graph_handle_ = LoadGraph("Image/Player_2.png");
		break;
	default:
		break;
	}
	quality_ = true;
	vector_ = 1;
	angle_ = 0;
	dance_timer_ = 0;
	dance_num_ = 0;
	is_carrier_ = false;
	player_state_ = Player_Air;
}
//�v���C���[�̃{�^�����͂��Ǘ�
void Player::Action() {
	const float kSpeed = 5.0f;
	if (Keyboard::getInstance()->CheckKey(KEY_INPUT_RIGHT) != 0) { //�E�L�[��������Ă�����
		vector_ = 1;
		//Move(&x_, kSpeed);//�E�Ɉړ�����
		MoveX(kSpeed);//�E�Ɉړ�����
	}
	if (Keyboard::getInstance()->CheckKey(KEY_INPUT_LEFT) != 0) { //���L�[��������Ă�����
		vector_ = -1;
		//Move(&x_, -kSpeed);//���Ɉړ�����
		MoveX(-kSpeed);//���Ɉړ�����
	}
	//��L�[����͂��ꂽ�Ƃ�
	if ((Keyboard::getInstance()->CheckKey(KEY_INPUT_UP) == 1 && player_state_ == Player_Land) ||//�v���C���[���n��ɂ���Ƃ���
		(Keyboard::getInstance()->CheckKey(KEY_INPUT_UP) > 1 && angle_ != 0)) {//��L�[����͂������Ă���Ƃ�
		Jump();
	}
	else if (angle_ != 0) {//��L�[�̓��͂����Ă��Ȃ��Ƃ��A�܂��̓W�����v���ɓ��͂���߂��Ƃ�
		angle_ = 0;//angle��0�ɐݒ肷��
	}
	//Space�L�[����͂����Ƃ�
	if (Keyboard::getInstance()->CheckKey(KEY_INPUT_SPACE) == 1) { 
		//�������̂������Ă���Ȃ�
		if (is_carrier_) Throw();//Throw������s��
			else Pick(); //Pick������s��
	}
	//���L�[����͂����Ƃ��A���������Ă����Ȃ�
	if (Keyboard::getInstance()->CheckKey(KEY_INPUT_DOWN) == 1 && is_carrier_)
		Put();//Put������s��

	if (Keyboard::getInstance()->CheckKey(KEY_INPUT_LCONTROL) == 1 || Keyboard::getInstance()->CheckKey(KEY_INPUT_RCONTROL) == 1)
		vector_ *= -1;

}
void Player::Push(float num, Object *object) {
	if (object->CanMoveX(num / 4)) {
		object->MoveX(num / 4);
		MoveX(num / 4);
		if (is_carrier_)carryon_->MoveX(num / 4);
	}
}
//�v���C���[��Item���E������
void Player::Pick() {
	Object *goods = nullptr;
	for (auto i : *stage_) {//�X�e�[�W��̃I�u�W�F�N�g���猟��
		if (Check(i) &&//
			(goods == nullptr ||
				abs(this->x_ - i->x_) < abs(this->x_ - goods->x_) ||
				(abs(this->x_ - i->x_) == abs(this->x_ - goods->x_) &&
				( i->Base() < goods->Base())))) {
			goods = i;//�����グ��Ώۂ�ݒ肷��
		}
	}
	if (goods != nullptr && goods->CanPicked(this)) {
		goods->Picked(this);
		is_carrier_ = true;
		carryon_ = goods;
	}
}
void Player::Put() {
	if (carryon_->CanPutted()) {
		carryon_->Putted();
		is_carrier_ = false;
	}
}
void Player::Throw() {
	if (carryon_->CanThrew()) {
		carryon_->Threw();
		is_carrier_ = false;
	}
}
//�v���C���[��Pick������s���ہAobject�����͈͓̔��ɂ��邩Check����֐�
//����:
//		object:�m�F����Object
bool Player::Check(Object *object) {
	bool check = false;
	if (object->quality_ &&object !=this && Base() > object->Top() && Top() < object->Base()) {
		if (vector_ == 1 &&//Player���E�������Ă���Ƃ�
			Right() <= object->Left() && Right() + width_ >= object->Left()) {
			check = true;
		}
		else if(vector_ == -1 &&//Player�����������Ă���Ƃ�
			Left() >= object->Right() && Left() - width_ <= object->Right()){
			check = true;
		}
	}
	return check;
}
//----------
//Player��Object�ɓ��������ۂ̈ʒu�̒�����Player�̏�Ԃ�ύX����
//�����F
//		check:int Check(float *point, float num,const Object *object)�̕Ԃ�l����A�I�u�W�F�N�g�̂ǂ��ɓ��������������߂�
//		object:�������I�u�W�F�N�g
void Player::Hit(int check, Object * object) {
	if (typeid(*object) == typeid(Terrain) || typeid(*object) == typeid(Item)) {
		switch (check) {
		case 1:
			x_ = object->Left() - width_ ;
			break;
		case 2:
			x_ = object->Right();
			break;
		case 3:
			y_ = object->Top() - height_;
			player_state_ = Player_Land;
			break;
		case 4:
			angle_ = 45;
			y_ = object->Base();
		default:
			break;
		}
	}
}
//----------
//Carryon(Player�������Ă���Item)��Object�ɓ��������ۂ̈ʒu�̒�����Player�̏�Ԃ�ύX����
//�����F
//		check:int Check(float *point, float num,const Object *object)�̕Ԃ�l����A�I�u�W�F�N�g�̂ǂ��ɓ��������������߂�
//		object:�������I�u�W�F�N�g
void Player::HitCarryon(int check,Object *object) {
	if (typeid(*object) == typeid(Terrain) || typeid(*object) == typeid(Item)) {
		switch (check) {
		case 1:
			carryon_->x_ = object->Left() - carryon_->width_;
			x_ = (carryon_->Left() + carryon_->Right() - this->width_) / 2;
			break;
		case 2:
			carryon_->x_ = object->Right();
			x_ = (carryon_->Left() + carryon_->Right() - this->width_) / 2;
			break;
		case 3:
			carryon_->y_ = object->Top() - carryon_->height_;
			y_ = carryon_->Base();
			player_state_ = Player_Land;
			break;
		case 4:
			carryon_->y_ = object->Base();
			y_ = carryon_->Base();
		default:
			break;
		}
	}
}
//Player�̃W�����v����
void Player::Jump() {
	if (angle_ > 90) angle_ = 90;//��L�[����͂������Ă�cos(angle_ * 3.141592f * 1 / 120)��0�ɂȂ�悤�ɂ���
	const float kJumpPower = 8;
	MoveY(-kJumpPower * (float)cos(angle_ * 3.141592f * 1 / 120));
	angle_++;//angle�𑝉���������
}
int Player::MapCheck(float num) {
	int check = 0;
	if (Right() + num > map_right_->Right()) check = 1;
	else if (Left() + num < map_left_->Left()) check = 2;
	return check;
}
void Player::MapHit(int mapcheck) {
	switch (mapcheck) {
	case 1:
		x_ = map_right_->Right() - width_;
		break;
	case 2:
		x_ = map_left_->Left();
		break;
	default:
		break;
	}
}
//���ɗ��������̊m�F
void Player::RetryCheck() {
	if(y_ > 480.0f) player_state_ = Player_Retry;//��ʉ��ɗ������ꍇ�A�v���C���[�����g���C��Ԃɂ���
}
//�N���A���ɗx��_���X���Ǘ�����
void Player::Dance() {
	switch (dance_num_) {
	//case 0:
	//	vector_ = -1;
	//	x_ += 2;
	//	dance_timer_++;
	//	if (dance_timer_ > 60) {//60/60fps = 1�b�ړ������Ƃ�
	//		dance_num_++;//���̈ړ��Ɉڍs����
	//		dance_timer_ = 0;//�^�C�}�[�����Z�b�g����
	//	}
	//	break;
	//case 1:
	//	vector_ = 1;
	//	x_ -= 2;
	//	dance_timer_++;
	//	if (dance_timer_ > 90) {
	//		dance_num_++;
	//		dance_timer_ = 0;
	//	}
	//	break;
	//case 2:
	//	vector_ = -1;
	//	x_ += 2;
	//	dance_timer_++;
	//	if (dance_timer_ > 30) {
	//		dance_num_++;
	//		dance_timer_ = 0;
	//	}
	//	break;
	//case 3:
	//	vector_ = -1;
	//	y_ -= 2;
	//	dance_timer_++;
	//	if (dance_timer_ > 15) {
	//		dance_num_++;
	//		dance_timer_ = 0;
	//	}
	//	break;
	//case 4:
	//	vector_ = -1;
	//	y_ += 2;
	//	dance_timer_++;
	//	if (dance_timer_ > 15) {
	//		dance_num_++;
	//		dance_timer_ = 0;
	//	}
	//	break;
	//case 5:
	//	vector_ = 1;
	//	y_ -= 2;
	//	dance_timer_++;
	//	if (dance_timer_ > 45) {
	//		dance_num_++;
	//		dance_timer_ = 0;
	//	}
	//	break;


	//case 0:
	//	vector_ = -1;
	//	y_ -= 2;
	//	dance_timer_++;
	//	if (dance_timer_ > 15) {
	//		dance_num_++;
	//		dance_timer_ = 0;
	//	}
	//	break;
	//case 1:
	//	vector_ = -1;
	//	y_ += 2;
	//	dance_timer_++;
	//	if (dance_timer_ > 15) {
	//		dance_num_++;
	//		dance_timer_ = 0;
	//	}
	//	break;
	//case 2:
	//	vector_ = -1;
	//	y_ += 2;
	//	dance_timer_++;
	//	if (dance_timer_ > 15) {
	//		dance_num_++;
	//		dance_timer_ = 0;
	//	}
	//	break;
	//case 3:
	//	vector_ = 1;
	//	y_ -= 2;
	//	dance_timer_++;
	//	if (dance_timer_ > 45) {
	//		dance_num_++;
	//		dance_timer_ = 0;
	//	}
	//	break;
	default:
		state_changer_->ChangeState(Game_Clear);
		break;
	}
}
void Player::Initialize(IStateChanger *stateChanger,std::vector<Object*>& stage){
	Object::Initialize(stateChanger, stage);
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
void Player::Update() {
	switch (player_state_) {
	case Player_Clear:
		Dance();
		break;
	case Player_Retry:
			state_changer_->ChangeState(Game_Retry);
			break;
	default:
		const float kGravity = 4.0f;
		MoveY(kGravity);
		Action();	
		RetryCheck();
		break;
	}
}
void Player::Draw() {
	if(vector_ ==1) DrawModiGraphF(x_, y_, x_ + width_, y_, x_ + width_, y_ + height_, x_, y_ + height_, graph_handle_, TRUE);
	else DrawModiGraphF(x_ + width_, y_, x_, y_, x_, y_ + height_, x_ + width_, y_ + height_, graph_handle_, TRUE);
}
//Player���ړ����鎲��num��ǉ��������ʁAobject�ɐڐG���邩�A�����ꍇ�ɂ͂ǂ̕����ɐڐG��������Ԃ�
//�Ԃ�l:
//		0:�ڐG�Ȃ�
//		1:object�̍����ɐڐG
//		2:object�̉E���ɐڐG
//		3:object�̏㑤�ɐڐG
//		4:object�̉����ɐڐG
//����:
//		point:�ړ����鎲�A&x��&y����͂���
//		num:�ړ����鎲�ɉ��Z���鐔��(�ړ����鋗��)
//		object:�ڐG���邩������s��Object
int Player::CheckX(float num, const Object *object) {
	int check = 0;
	if (object->quality_ &&
		((!is_carrier_ && object != this) ||//���������Ă��Ȃ����A�{�l������
		(is_carrier_ && object != carryon_ && object != this))) {//���������Ă���Ƃ��A�����Ă�����̂�Player�ɑ΂���ڐG������Ȃ���
		if (Object::Check(x_ + num,y_, object)) {
			if (num > 0) check = 1;//�n�`�̏㑤����Փ˂�����
			else check = 2;//�n�`�̉�����Փ˂�����
		}
	}
	return check;
}
int Player::CheckY(float num, const Object *object) {
	int check = 0;
	if (object->quality_ &&
		((!is_carrier_ && object != this) ||//���������Ă��Ȃ����A�{�l������
		(is_carrier_ && object != carryon_ && object != this))) {//���������Ă���Ƃ��A�����Ă�����̂�Player�ɑ΂���ڐG������Ȃ���
		if (Object::Check(x_,y_ + num, object)) {
			if (num > 0) check = 3;//�n�`�̏㑤����Փ˂�����
			else check = 4;//�n�`�̉�����Փ˂�����
		}
	}
	return check;
}
//Player������Object�ɂ���Ĉړ������ꍇ�A���������Ƃ��ł��邩��Ԃ�
bool Player::CanMoveX(float num) {
	bool can_move = true;
	for (int i = 0; i != (*stage_).size();i++) {
		if (CheckX(num, (*stage_)[i]) != 0 && (*stage_)[i]->CanMoveX(num/4)) {
			can_move = false;
			break;
		}
	}
	return can_move;
}
//Player������Object�ɂ���Ĉړ������ꍇ�A���������Ƃ��ł��邩��Ԃ�
bool Player::CanMoveY(float num) {
	bool can_move = true;
	for (int i = 0; i != (*stage_).size();i++) {
		if (CheckY(num, (*stage_)[i]) != 0 && (*stage_)[i]->CanMoveY(num/4)) {
			can_move = false;
			break;
		}
	}
	return can_move;
}
//�v���C���[�̈ړ����s��
void Player::MoveX(float num) {
	bool hit = false;
	if (is_carrier_) {//�����w�����Ă���Ƃ�
		for (auto i : (*stage_)) {
				//�w�����Ă��镨�̓����蔻����`�F�b�N����
			if (carryon_->CheckX(num, i) != 0) {
				//�I�u�W�F�N�g�ɐڐG���Ă��鎞
				//if (player_state_ == Player_Land) {
				//	//�����Ɉړ����悤�Ƃ��Ă���Ƃ������v���C���[���n�ʂɂ���Ƃ�
				//	Push(num, i);//�I�u�W�F�N�g������
				//}
				HitCarryon(carryon_->CheckX(num, i), i);//Hit�������̃v���C���[�̈ʒu�𒲐�����
				hit = true;
				break;
			}
		}
	}
	if (!hit) {//�����w�����ĂȂ��Ƃ��A�܂��͔w�����Ă�����͉̂���������Ȃ��ꍇ
		for (auto i : (*stage_)) {
			if (CheckX(num, i) != 0) {
				if (player_state_ == Player_Land) {
					//�����Ɉړ����悤�Ƃ��Ă���Ƃ������v���C���[���n�ʂɂ���Ƃ�
					Push(num, i);//�I�u�W�F�N�g������
				}
				Hit(CheckX(num, i), i);//Hit�������̃v���C���[�̈ʒu�𒲐�����
				hit = true;
				break;
			}
		}
	}
	//�}�b�v�O�Ɉړ����Ă��܂����m�F���鏈��
	if (MapCheck(num) != 0) {
		hit = true;
		MapHit(MapCheck(num));
	}
	if (!hit) {//�ړ���ɉ����I�u�W�F�N�g���Ȃ��A�}�b�v�O�Ɉړ����Ȃ��ꍇ
		x_ += num;
	}
}
//�v���C���[�̈ړ����s��
void Player::MoveY(float num) {
	bool hit = false;
	if (is_carrier_) {//�����w�����Ă���Ƃ�
		for (auto i : (*stage_)) {
				//�w�����Ă��镨�̓����蔻����`�F�b�N����
			if (carryon_->CheckY(num, i) != 0) {
				HitCarryon(carryon_->CheckY(num, i), i);//Hit�������̃v���C���[�̈ʒu�𒲐�����
				hit = true;
				break;
			}
		}
	}
	if (!hit) {//�����w�����ĂȂ��Ƃ��A�܂��͔w�����Ă�����͉̂���������Ȃ��ꍇ
		for (auto i : (*stage_)) {
			if (CheckY(num, i) != 0) {
				Hit(CheckY(num, i), i);//Hit�������̃v���C���[�̈ʒu�𒲐�����
				hit = true;
				break;
			}
		}
	}
	//�}�b�v�O�Ɉړ����Ă��܂����m�F���鏈��
	if (!hit) {//�ړ���ɉ����I�u�W�F�N�g���Ȃ��A�}�b�v�O�Ɉړ����Ȃ��ꍇ
		y_ += num;
		player_state_ = Player_Air;//y���v���C���[�̏�Ԃ��󒆂ɂ����Ԃɂ���
	}
}
//���̃I�u�W�F�N�g�������グ���邩���`�F�b�N����
bool Player::CanPicked(const Object * object) {
	bool can_picked = true;
	for (auto i : (*stage_)) {
		if (Object::Check(object->x_ - width_, object->y_ - height_, i) != 0) {
			can_picked = false;
			break;
		}
	}
	return can_picked;
}
//���̃I�u�W�F�N�g�������グ����Ƃ��̊֐�(������)
void Player::Picked(Object *object) {
}
//�N���A�����Ƃ��̊֐�
void Player::Clear() {
	player_state_ = Player_Clear;
}
//���g���C�����Ƃ��̊֐�
void Player::Retry() {
	Object::Retry();
	player_state_ = Player_Air;
	is_carrier_ = false;
	vector_ = 1;
}
//�N���A�o���邩��Ԃ��֐�
// true:�N���A�\,false:�N���A�ł��Ȃ�
bool Player::CanClear() {
	bool canclear_ = true;
	if (player_state_ == Game_Clear) {//���łɃN���A���Ă���ꍇ
		canclear_ = false;
	}
	return canclear_;
}