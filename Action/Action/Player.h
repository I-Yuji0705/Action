#pragma once
#include "Object.h"
#include "Terrain.h"
#include "IStateChanger.h"
//�L�����N�^�[�̏�ԏ��
enum StateCharacter {
	State_Land,//�n��ɂ���
	State_Air,//�󒆂ɂ���
	State_Clear,
	State_Retry
};
class Player :public Object{
private:
	int kaku;
	StateCharacter playerState;
	bool isCarrier;//�����������Ă��邩��Ԃ�
	Object *carryon;//�����Ă��镨�̃A�h���X
	int danceTimer,danceNum;//��̓����Ɋ|���鎞�ԂƁA�����̐�
	void Action();//�v���C���[�̍s��
	bool Check(Object *object);
	void Hit(int check, Object *object);
	void Pick();
	void Throw();
	void Put();
	void Dance();//�N���A���̗x��
	void Push(Object *object);
	Object *mapLeft, *mapRight;
	int MapCheck(float *point, float num);
public :
	void Clear()override;
	bool CanPicked(Object *object)override;
	void Move(float *point, float num)override;//�ړ����s���A�ړ��ł�������Ԃ�
	void Initialize(IStateChanger *stateChanger,Object **stage)override;
	void Initialize(IStateChanger *stateChanger);
	void RetryCheck();//���g���C������K�v�����邩(���ɗ�������)���m�F����
	void Retry()override;
	void Set(float x, float y, float height, float width, int objNum)override;
	void Update();
	void Draw()override;
	void Picked(Object *object)override;
	void Putted()override;
	bool CanPutted()override;
	int Check(float *point,float num,Object *object);
};