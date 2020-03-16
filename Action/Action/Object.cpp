#include "Object.h"
#include "Player.h"
#include <typeinfo.h>
#include "DxLib.h"

//Dance��public�ɂ��āA
//�_���X���ɌĂяo���悤�ɂ����CanClear�͂���Ȃ����A
//ClearArea��Sound��n���K�v���Ȃ��H
//�������́A�N���A���Ă��邩��
//bool�Ŕ��f����ׂ��H

///<summary>
///<para>�R���X�g���N�^</para>
///<para>�I�u�W�F�N�g�̍����X���W��Y���W�A�����Əc����ݒ肷��</para>
///<para>�܂��A�����ʒu��ۑ�����</para>
///<para>����:</para>
///<param name="x"><para>x:Object�̍����X���W</para></param>
///<param name="y"><para>y:Object�̍����Y���W</para></param>
///<param name="height"><para>height:Object�̍�����E�܂ł̉���</para></param>
///<param name="width"><para>width:Object�̏ォ�牺�܂ł̏c��</para></param>
///</summary>
Object::Object(float x, float y, float height, float width) {
	Set(x, y, height, width);
	this->retry_pos_x_ = x;
	this->retry_pos_y_ = y;
}

///<summary>
///<para>�I������</para>
///<para>��������̉摜���폜����</para>
///</summary>
void Object::Finalize() {
	DeleteGraph(graph_handle_);
}

///<summary>
///<para>�I�u�W�F�N�g�̍��[�̂����W��Ԃ�</para>
///<para>�߂�l:</para>
///<returns>
///<para>�I�u�W�F�N�g�̍��[�̂����W</para>
///</returns>
///</summary>
float Object::Left() const {
	return x_;
}

///<summary>
///<para>�I�u�W�F�N�g�̉E�[�̂����W��Ԃ�</para>
///<para>�߂�l:</para>
///<returns>
///<para>�I�u�W�F�N�g�̉E�[�̂����W</para>
///</returns>
///</summary>
float Object::Right() const {
	return x_ + width_;
}

///<summary>
///<para>�I�u�W�F�N�g�̏�ӂ̂����W��Ԃ�</para>
///<para>�߂�l:</para>
///<returns>
///<para>�I�u�W�F�N�g�̏�ӂ̂����W</para>
///</returns>
///</summary>
float Object::Top() const {
	return y_;
}

///<summary>
///<para>�I�u�W�F�N�g�̉��ӂ̂����W��Ԃ�</para>
///<para>�߂�l:</para>
///<returns>
///<para>�I�u�W�F�N�g�̉��ӂ̂����W</para>
///</returns>
///</summary>
float Object::Base() const {
	return y_ + height_;
}

///<summary>
///<para>�I�u�W�F�N�g�̒��S��X���W��Ԃ�</para>
///<para>�߂�l:</para>
///<returns>
///<para>�I�u�W�F�N�g�̒��S��X���W</para>
///</returns>
///</summary>
float Object::Center_X() const{
	return x_ + width_ / 2;
}

///<summary>
///<para>�I�u�W�F�N�g�̉�����Ԃ�</para>
///<para>�߂�l:</para>
///<returns>
///<para>�I�u�W�F�N�g�̉���</para>
///</returns>
///</summary>
float Object::GetWidth() const {
	return width_;
}

///<summary>
///<para>�I�u�W�F�N�g�̏c����Ԃ�</para>
///<para>�߂�l:</para>
///<returns>
///<para>�I�u�W�F�N�g�̏c��</para>
///</returns>
///</summary>
float Object::GetHeight() const {
	return height_;
}

///<summary>
///<para>�I�u�W�F�N�g���w�肵�����W�ɐݒ肷��</para>
///<para>����:</para>
///<param name="x"><para>x:�ݒ肷��Object�̍����X���W</para></param>
///<param name="y"><para>y:�ݒ肷��Object�̍����Y���W</para></param>
///</summary>
void Object::Set(float x, float y) {
	this->x_ = x;
	this->y_ = y;
}

///<summary>
///<para>�I�u�W�F�N�g���w�肵�����W�ɐݒ肷��</para>
///<para>�ǉ��ŃI�u�W�F�N�g�̏c���A������ݒ肷��</para>
///<para>����:</para>
///<param name="x"><para>x:�ݒ肷��Object�̍����X���W</para></param>
///<param name="y"><para>y:�ݒ肷��Object�̍����Y���W</para></param>
///<param name="height"><para>height:Object�̍�����E�܂ł̉���</para></param>
///<param name="width"><para>width:Object�̏ォ�牺�܂ł̏c��</para></param>
///</summary>
void Object::Set(float x, float y, float height, float width) {
	Set(x, y);
	this->width_ = width;
	this->height_ = height;
}

//�I�u�W�F�N�g�̕`��
//void Object::Draw() {
//	DrawBoxAA(x_, y_, x_ + width_, y_ + height_, GetColor(0, 0, 0), TRUE);//Float�^�̎l�_�̍��W����O�g��`��
//	const float distance = 5.0f;
//	DrawModiGraphF(x_ + distance, y_ + distance, x_ + width_ - distance, y_ + distance,
//		x_ + width_ - distance, y_ + height_ - distance, x_, y_ + height_ - distance,graph_handle_, TRUE);//Float�^�̎l�_�̍��W����摜��`��
//}

///<summary>
///<para>������悤�Ƃ��Ă��鐔������A������������邱�Ƃ̂ł��鐔����Ԃ�</para>
///<para>�f�t�H���g���Ə��0��Ԃ�</para>
///<para>����:</para>
///<param name="num"><para>num:���݂̈ʒu���瓮�������Ƃ��Ă�����W�ւ̍�</para></param>
///<para>�߂�l:</para>
///<returns>
///<para>num�ɑ΂��āA���ۂɂ���Object�𓮂����鋗��</para>
///</returns>
///</summary>
float Object::CanPushed(float num) {
	return 0;
}

///<summary>
///<para>Object�Ɏ�����邩��Ԃ�</para>
///<para>�f�t�H���g���Ə��false��Ԃ�</para>
///<para>����:</para>
///<param name="object"><para>object:����������Object</para></param>
///<para>�߂�l:</para>
///<returns>
///<para>true:�����������Ƃ��ł���</para>
///<para>false:�����������Ƃ��ł��Ȃ�</para>
///</returns>
///</summary>
bool Object::CanPicked(const Object *object) {
	return false;
}

///<summary>
///<para>��Object���u����邱�Ƃ��ł��邩��Ԃ�</para>
///<para>�f�t�H���g���Ə��false��Ԃ�</para>
///<para>�߂�l:</para>
///<returns>
///<para>true:�����������Ƃ��ł���</para>
///<para>false:�����������Ƃ��ł��Ȃ�</para>
///</returns>
///</summary>
bool Object::CanPutted() {
	return false;
}

///<summary>
///<para>��Object���������邱�Ƃ��ł��邩��Ԃ�</para>
///<para>�f�t�H���g���Ə��false��Ԃ�</para>
///<para>�߂�l:</para>
///<returns>
///<para>true:���������邱�Ƃ��ł���</para>
///<para>false:�����𓊂��邱�Ƃ��ł��Ȃ�</para>
///</returns>
///</summary>
bool Object::CanThrew() {
	return false;
}

///<summary>
///<para>���g���C����</para>
///<para>�����ʒu�ɍ��W��ݒ肷��</para>
///</summary>
void Object::Retry() {
	Set(retry_pos_x_, retry_pos_y_);
}

///<summary>
///<para>���N���A�ł��邩��Ԃ�</para>
///<para>�f�t�H���g���Ə��false��Ԃ�</para>
///<returns>
///<para>true:���������邱�Ƃ��ł���</para>
///<para>false:�����𓊂��邱�Ƃ��ł��Ȃ�</para>
///</returns>
///</summary>
bool Object::CanClear() {
	return false;
}
