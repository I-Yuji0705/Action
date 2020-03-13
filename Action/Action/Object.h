#pragma once
#include "IGameStateChanger.h"
#include "Collision.h"
#include <vector>
#include "Sound.h"

class Collision;
class Sound;
//�X�e�[�W��̃I�u�W�F�N�g�̒��ۃN���X
class Object {
protected:
	Sound* sound_;
	float retry_pos_x_, retry_pos_y_;//�����ʒu
	int graph_handle_/*,object_number_*/;//�I�u�W�F�N�g�̉摜�A��ނ��Ƃ̔ԍ�
public:
	IGameStateChanger *state_changer_;
	Object(float x, float y, float height, float width,Sound* sound);
	float x_, y_;//�I�u�W�F�N�g�̉E��x���W�A���y���W
	float width_, height_;//�I�u�W�F�N�g�̉����A�c��
	int vector_;//�����Ă������������.1:�E������,-1:��������
	bool quality_;//�ڐG���肪���邩�ǂ�����Ԃ�
	void Finalize();
	float Left() const;//�I�u�W�F�N�g�̍�����X��
	float Right() const;//�I�u�W�F�N�g�̉E����X��
	float Top() const;//�I�u�W�F�N�g�̏㕔��Y��
	float Base() const;//�I�u�W�F�N�g�̉�����Y��
	float Center_X() const;//�I�u�W�F�N�g�̒�����x���W
	float GetWidth() const;//�I�u�W�F�N�g�̉���
	float GetHeight() const;//�I�u�W�F�N�g�̏c��
	void Set(float x, float y);//�I�u�W�F�N�g�̍Đݒu
	void Set(float x, float y, float height, float width);//�I�u�W�F�N�g�̍Đݒu�y�уT�C�Y�̕ύX
	virtual void Initialize(IGameStateChanger *stateChanger,Collision *collision);//����������
	virtual void Update(){};//�X�V����
	virtual void Draw();//�`�ʏ���
	virtual float CanPushed(float num);//������邩�ǂ�����Ԃ�
	virtual void Pushed(float num);//�����ꂽ���̓���
	virtual bool CanMoveY(float num);//�ړ����\���ǂ�����Ԃ�
	virtual bool CanPicked(const Object *object);//�����グ���邩��Ԃ�
	virtual void Picked(Object *object) {};//�����グ��ꂽ���̏���
	virtual bool CanPutted();//�u���邩�ǂ�����Ԃ�
	virtual void Putted() {};//�u���ꂽ���̏���
	virtual bool CanThrew();//�������邩��Ԃ�
	virtual void Threw() {};//������ꂽ���̏���
	virtual void Retry();//���g���C������ۂ̏���
	virtual bool CanClear();
	virtual void Clear() {};//�N���A�����𖞂������Ƃ��̏���
};