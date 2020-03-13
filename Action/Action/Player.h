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
	StateCharacter playerState;
	Object *mapLeft, *mapRight;
	Object *carryon;//�����Ă��镨�̃A�h���X
	bool isCarrier;//�����������Ă��邩��Ԃ�
	int angle;//�W�����v���Ă���Ԃ̎���
	int danceTimer,danceNum;//��̓����Ɋ|���鎞�ԂƁA�����̐�
	void Action();//�v���C���[�̍s��
	void Push(float num,Object *object);
	void Pick();
	void Put();
	void Throw();
	bool Check(Object *object);
	void Hit(int check, Object *object);
	int MapCheck(float *point, float num);
	void RetryCheck();//���g���C������K�v�����邩(���ɗ�������)���m�F����
	void Dance();//�N���A���̓����̏���
public :
	void Set(float x, float y, float height, float width, int objNum)override;
	void Initialize(IStateChanger *stateChanger,Object *stage[])override;
	void Update()override;
	void Draw()override;
	int Check(float *point, float num, Object *object)override;
	bool CanMove(float *point, float num)override;
	void Move(float *point, float num)override;//�ړ����s���A�ړ��ł�������Ԃ�
	bool CanPicked(Object *object)override;
	void Picked(Object *object)override;
	void Clear()override;
	void Retry()override;
};