#pragma once
#include "IStateChanger.h"
#include <vector>
//�X�e�[�W��̃I�u�W�F�N�g�̊��N���X
class Object {
protected:
	//Object **stage_;
	std::vector<Object*> *stage_;
	
	IStateChanger *state_changer_;
	float retry_pos_x_, retry_pos_y_;//�����ʒu
	int graph_handle_/*,object_number_*/;//�I�u�W�F�N�g�̉摜�A��ނ��Ƃ̔ԍ� 
public:
	//static int object_num_;
	int object_number_;
	float x_, y_;
	float width_, height_;//�I�u�W�F�N�g�̉E�̍��W�A��̍��W�A�����A�c��
	int vector_;//�����Ă������������.1:�E������,-1:��������
	bool quality_;//�ڐG���肪���邩�ǂ�����Ԃ�
	Object(float x, float y, float height, float width, int object_number);//����������
	bool Check(float x, float y,const Object *object);
	void Finalize();
	float Left() const;//�I�u�W�F�N�g�̍�����X��
	float Right() const;//�I�u�W�F�N�g�̉E����X��
	float Top() const;//�I�u�W�F�N�g�̏㕔��Y��
	float Base() const;//�I�u�W�F�N�g�̉�����Y��
	float Center_X() const;
	void RelaySet(float x,float y);
	void Set(float x, float y);//�I�u�W�F�N�g�̍Đݒu
	void Set(float x, float y, float height, float width);//�I�u�W�F�N�g�̍Đݒu�y�уT�C�Y�̕ύX
	virtual void Initialize(IStateChanger *stateChanger,std::vector<Object*>& stage);
	virtual void Update(){};
	virtual void Draw();
	//virtual int Check(float *point, float num, const Object *object);//point����num��ǉ������ہA����object�ɓ����邩�A�ǂ̕����ɓ�����������Ԃ�
	virtual int CheckX(float num, const Object *object);//point����num��ǉ������ہA����object�ɓ����邩�A�ǂ̕����ɓ�����������Ԃ�
	virtual int CheckY(float num, const Object *object);//point����num��ǉ������ہA����object�ɓ����邩�A�ǂ̕����ɓ�����������Ԃ�
	//virtual bool CanMove(float *point,float num);//�ړ����\���ǂ�����Ԃ�
	virtual bool CanMoveX(float num);//�ړ����\���ǂ�����Ԃ�
	virtual bool CanMoveY(float num);//�ړ����\���ǂ�����Ԃ�
	//virtual void Move(float *point, float num) {};//�ړ����s��
	virtual void MoveX(float num) {};
	virtual void MoveY(float num) {};
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