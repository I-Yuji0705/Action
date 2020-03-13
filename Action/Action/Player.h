#pragma once
#include "Object.h"
#include "Terrain.h"
#include "IStateChanger.h"
//�L�����N�^�[�̏�ԏ��
enum StateCharacter {
	Player_Land,//�n��ɂ���
	Player_Air,//�󒆂ɂ���
	Player_Clear,
	Player_Retry
};
class Player :public Object{
private:
	StateCharacter player_state_;
	Object *map_left_, *map_right_;
	Object *carryon_;//�����Ă��镨�̃A�h���X
	bool is_carrier_;//�����������Ă��邩��Ԃ�
	int angle_;//�W�����v���Ă���Ԃ̎���
	int dance_timer_,dance_num_;//��̓����Ɋ|���鎞�ԂƁA�����̐�
	void Action();//�v���C���[�̍s��
	void Push(float num,Object *object);
	void Pick();
	void Put();
	void Throw();
	bool Check(Object *object);
	int MapCheck(float num);
	void MapHit(int mapcheck);
	void RetryCheck();//���g���C������K�v�����邩(���ɗ�������)���m�F����
	void Dance();//�N���A���̓����̏���
	void Hit(int check ,Object * object);
	void HitCarryon(int check, Object *object);
	void Jump();
public :
	Player(float x, float y, float height, float width, int object_number);
	void Initialize(IStateChanger *stateChanger,std::vector<Object*>& stage) override;
	void Update()override;
	void Draw()override;
	int CheckX(float num, const Object *object)override;
	int CheckY(float num, const Object *object)override;
	bool CanMoveX(float num)override;
	bool CanMoveY(float num)override;
	void MoveX(float num)override;//�ړ����s���A�ړ��ł�������Ԃ�
	void MoveY(float num)override;
	bool CanPicked(const Object *object)override;
	void Picked(Object *object)override;
	void Clear()override;
	void Retry()override;
	bool CanClear()override;
};