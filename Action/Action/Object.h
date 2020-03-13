#pragma once
#include "Task.h"
#include "IStateChanger.h"
//�X�e�[�W��̃I�u�W�F�N�g�̊��N���X
class Object :public Task {
protected:
	Object **stage;
	IStateChanger *stateChanger;
	float retryX, retryY;//�����ʒu
public:
	int vector;//�����Ă������������.1:�E������,-1:��������
	bool quality;//�ڐG���肪���邩�ǂ�����Ԃ�
	static int object_num;
	void Finalize() override;
	virtual void Update() override {};
	void Draw() override ;
	float x, y, width, height;//�I�u�W�F�N�g�̉E�̍��W�A��̍��W�A�����A�c��
	int graphHandle,objNum;//�I�u�W�F�N�g�̉摜�A��ނ��Ƃ̔ԍ�
	virtual void Set(float x, float y, float height, float width, int objNum);//����������
	void Set(float x, float y, float height, float width);
	void Set(float x, float y);
	float Left();
	float Right();
	float Top();
	float Base();
	virtual void Move(float *point, float num);//�ړ����s��
	virtual bool CanPicked(Object *object);//�����グ���邩��Ԃ�
	virtual void Picked(Object *object);//�����グ��ꂽ���̏���
	virtual void Putted();//�u���ꂽ���̏���
	virtual bool CanPutted();//�u���邩�ǂ�����Ԃ�
	virtual int Check(float *point, float num, Object *object);
	virtual bool CanThrew();//�������邩��Ԃ�
	virtual void Threw();//������ꂽ���̏���
	virtual void Retry();//���g���C������ۂ̏���
	void RelaySet(float x,float y);
	int Check(float x, float y, Object *object);
	virtual void Initialize(Object **stage);
	virtual void Initialize(IStateChanger *stateChanger, Object **stage);
	virtual void Clear() {};
};