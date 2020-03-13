#include "Object.h"
#include "Player.h"
#include <typeinfo.h>
#include "DxLib.h"

Object::Object(float x, float y, float height, float width,Sound* sound) {
	Set(x, y, height, width);
	this->retry_pos_x_ = x;
	this->retry_pos_y_ = y;
	sound_ = sound;
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
//�I�u�W�F�N�g�̒��S��X���W��Ԃ�
float Object::Center_X() const{
	return x_ + width_ / 2;
}
//�I�u�W�F�N�g�̉�����Ԃ�
float Object::GetWidth() const {
	return width_;
}
//�I�u�W�F�N�g�̏c����Ԃ�
float Object::GetHeight() const {
	return height_;
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
void Object::Initialize(IGameStateChanger *stateChanger,Collision *collision){
	this->state_changer_ = stateChanger;
}
//�I�u�W�F�N�g�̕`��
void Object::Draw() {
	DrawBoxAA(x_, y_, x_ + width_, y_ + height_, GetColor(0, 0, 0), TRUE);//Float�^�̎l�_�̍��W����O�g��`��
	const float distance = 5.0f;
	DrawModiGraphF(x_ + distance, y_ + distance, x_ + width_ - distance, y_ + distance,
		x_ + width_ - distance, y_ + height_ - distance, x_, y_ + height_ - distance,graph_handle_, TRUE);//Float�^�̎l�_�̍��W����摜��`��
}
//ObjectX���Ɉړ��ł��邩��Ԃ� ���f�t�H���g���Ə��0��Ԃ�
//����:
//			num:�I�u�W�F�N�g�̎����ǂ̒��x�ړ������邩�����߂�
float Object::CanPushed(float num) {
	return 0;
}
void Object::Pushed(float num) {
}
////ObjectY���ɂ��ړ��ł��邩��Ԃ� ���f�t�H���g���Ə��false��Ԃ�
////����:
////			num:�I�u�W�F�N�g�̎����ǂ̒��x�ړ������邩�����߂�
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