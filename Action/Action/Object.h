#pragma once
#include "Task.h"
#include "IStateChanger.h"
//�X�e�[�W��̃I�u�W�F�N�g�̊��N���X
class Object :public Task {
protected:
	Object **stage;
	IStateChanger *stateChanger;
	float retryX, retryY;//�����ʒu
	int graphHandle,objNum;//�I�u�W�F�N�g�̉摜�A��ނ��Ƃ̔ԍ� 
	bool Check(float x, float y, Object *object);
public:
	static int object_num;
	float x, y,width, height;//�I�u�W�F�N�g�̉E�̍��W�A��̍��W�A�����A�c��
	int vector;//�����Ă������������.1:�E������,-1:��������
	bool quality;//�ڐG���肪���邩�ǂ�����Ԃ�
	void Finalize() override;
	float Left();//�I�u�W�F�N�g�̍�����X��
	float Right();//�I�u�W�F�N�g�̉E����X��
	float Top();//�I�u�W�F�N�g�̏㕔��Y��
	float Base();//�I�u�W�F�N�g�̉�����Y��
	void RelaySet(float x,float y);
	void Set(float x, float y);//�I�u�W�F�N�g�̍Đݒu
	void Set(float x, float y, float height, float width);//�I�u�W�F�N�g�̍Đݒu�y�уT�C�Y�̕ύX
	virtual void Set(float x, float y, float height, float width, int objNum);//����������
	virtual void Initialize(IStateChanger *stateChanger, Object *stage[]);
	virtual void Update() override {};
	virtual void Draw() override ;
	virtual int Check(float *point, float num, Object *object);//point����num��ǉ������ہA����object�ɓ����邩�A�ǂ̕����ɓ�����������Ԃ�
	virtual bool CanMove(float *point,float num);//�ړ����\���ǂ�����Ԃ�
	virtual void Move(float *point, float num) {};//�ړ����s��
	virtual bool CanPicked(Object *object);//�����グ���邩��Ԃ�
	virtual void Picked(Object *object) {};//�����グ��ꂽ���̏���
	virtual bool CanPutted();//�u���邩�ǂ�����Ԃ�
	virtual void Putted() {};//�u���ꂽ���̏���
	virtual bool CanThrew();//�������邩��Ԃ�
	virtual void Threw() {};//������ꂽ���̏���
	virtual void Retry();//���g���C������ۂ̏���
	virtual void Clear() {};//�N���A�����𖞂������Ƃ��̏���
};