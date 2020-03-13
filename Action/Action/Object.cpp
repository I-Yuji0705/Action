#include "Object.h"
#include "Player.h"
#include "DxLib.h"

Object::Object(float x, float y, float height, float width, int object_number) {
	Set(x, y, height, width);
	this->retry_pos_x_ = x;
	this->retry_pos_y_ = y;
	this->object_number_ = object_number;
}
//�I������
void Object::Finalize() {
	
	DeleteGraph(graph_handle_);
}
//�I�u�W�F�N�g�̍��[�̂����W��Ԃ�
float Object::Left() const {
	return x_;
}
//�I�u�W�F�N�g�̉E�[�̂����W��Ԃ�
float Object::Right() const {
	return x_ + width_;
}
//�I�u�W�F�N�g�̏�ӂ̂����W��Ԃ�
float Object::Top() const {
	return y_;
}
//�I�u�W�F�N�g�̉��ӂ̂����W��Ԃ�
float Object::Base() const {
	return y_ + height_;
}
float Object::Center_X() const{
	return x_ + width_ / 2;
}
//�Ώۂ̃I�u�W�F�N�g�ƍ��W��ŐڐG���邩��Ԃ�
//����:
//		x:�ړ���̉E�[�̂����W,y:�ړ���̏�[�̂����W,object:�ڐG���Ă��邩�𔻒肷��Object
//�Ԃ�l: true:object�Ƃ͐ڐG���Ă���,false:object�Ƃ͐ڐG���Ă��Ȃ�
bool Object::Check(float x, float y,const Object *object) {
	bool check = false;
	if (object->quality_ &&
		y + height_ > object->Top() && y < object->Base() &&
		x + width_ > object->Left() && x < object->Right())
		check = true;
	return check;
}
//Retry���ɃI�u�W�F�N�g�̍Ĕz�u������W�ݒ�
//����:
//			x:�w���̃I�u�W�F�N�g�̉E�[��x���W
//			y:�w���̃I�u�W�F�N�g�̏�[��y���W
void Object::RelaySet(float x,float y) {
	this->retry_pos_x_ = x;
	this->retry_pos_y_ = y;
}
//�I�u�W�F�N�g���w�肵�����W�ɐݒ肷��
//����:
//			x:�w���̃I�u�W�F�N�g�̉E�[��x���W
//			y:�w���̃I�u�W�F�N�g�̏�[��y���W
void Object::Set(float x, float y) {
	this->x_ = x;
	this->y_ = y;
}
//�I�u�W�F�N�g�����W�Ɉړ������ɃI�u�W�F�N�g�̏c���A������ݒ肷��
//����:
//			x:�w���̃I�u�W�F�N�g�̉E�[��x���W
//			y:�w���̃I�u�W�F�N�g�̏�[��y���W
//			height:�I�u�W�F�N�g�̏c��
//			width:�I�u�W�F�N�g�̏c��
void Object::Set(float x, float y, float height, float width) {
	Set(x, y);
	this->width_ = width;
	this->height_ = height;
}
//�I�u�W�F�N�g�̏�����
//����:
//			stageChanger:StageManeger��state��ύX����N���X�̐ݒ�
//			stage:�I�u�W�F�N�g���瑼�̃I�u�W�F�N�g���m�F����ۂɎg�p
void Object::Initialize(IStateChanger *stateChanger,std::vector<Object*>& stage){
	this->state_changer_ = stateChanger;
	this->stage_ = &stage;
}
//�I�u�W�F�N�g�̕`��
void Object::Draw() {
	DrawModiGraphF(x_, y_, x_ + width_, y_,x_ + width_, y_ + height_, x_, y_ + height_,graph_handle_, TRUE);//Float�^�̎l�_�̍��W����摜��`��
}
//�I�u�W�F�N�g���ړ����悤�Ƃ����ہA�Ώۂ̃I�u�W�F�N�g�ɐڐG���邩�A�ǂ����ڐG�����ۂɂǂ̕����ɐڐG��������Ԃ�
//����:
//			point:�ړ����悤�Ƃ��Ă���I�u�W�F�N�g�̎� x:x��,y:y��
//			num:�I�u�W�F�N�g�̎����ǂ̒��x�ω������邩�����߂�
//			object:�ڐG���Ă��邩�𔻒肷��Object
//�Ԃ�l:
//				0:�ڐG�Ȃ�
//				1:�Ώۂ�object�ɍ�����ڐG
//				2:�Ώۂ�object�ɉE����ڐG
//				3:�Ώۂ�object�ɏォ��ڐG
//				4:�Ώۂ�object�ɉ�����ڐG
int Object::CheckX(float num, const Object *object) {
	int check = 0;
	if (object != this && object->quality_ && Object::Check(x_ + num, y_, object)) {
		if (num > 0) check = 1;//�n�`�̏㑤����Փ˂�����
		else check = 2;//�n�`�̉�����Փ˂�����
	}
	return check;
}
int Object::CheckY(float num, const Object *object) {
	int check = 0;
	if (object != this && object->quality_ && Object::Check(x_, y_ + num, object)) {
		if (num > 0) check = 3;//�n�`�̏㑤����Փ˂�����
		else check = 4;//�n�`�̉�����Փ˂�����
	}
	return check;
}
//Object���ړ��ł��邩��Ԃ� ���f�t�H���g���Ə��false��Ԃ�
//����:
//			point:�ړ����悤�Ƃ��Ă���I�u�W�F�N�g�̎� x:x��,y:y��
//			num:�I�u�W�F�N�g�̎����ǂ̒��x�ω������邩�����߂�
bool Object::CanMoveX(float num) {
	return false;
}
bool Object::CanMoveY(float num) {
	return false;
}
//Object�������グ���邩��Ԃ� ���f�t�H���g���Ə��false��Ԃ�
//����:
//			object:�����グ�悤�Ƃ��Ă���Ώ�
bool Object::CanPicked(const Object *object) {
	return false;
}
//Object��u�����Ƃ��o���邩��Ԃ� ���f�t�H���g���Ə��false��Ԃ�
bool Object::CanPutted() {
	return false;
}
//Object�𓊂����邩��Ԃ� ���f�t�H���g���Ə��false��Ԃ�
bool Object::CanThrew() {
	return false;
}
//Retry�������ۂ̑���
void Object::Retry() {
	Set(retry_pos_x_, retry_pos_y_);
}
//Object�ɂ����Clear�o���邩��Ԃ� ���f�t�H���g���Ə��false��Ԃ�
bool Object::CanClear() {
	return false;
}