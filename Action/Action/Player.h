#pragma once
#include "Object.h"
#include "Terrain.h"
#include "Collision.h"
#include "PlayerAction.h"
//�L�����N�^�[�̏�ԏ��
enum StateCharacter {
	Player_Land,//�n��ɂ���
	Player_Air,//�󒆂ɂ���
	Player_Clear,//�N���A����
};
enum PlayerActionList {
	Player_MoveRight,//�E�ړ�
	Player_MoveLeft,//���ړ�
	Player_Jump,//�W�����v
	Player_Throw,//������
	Player_Pick,//�E��
	Player_Put,//�u��
	Player_Gravity,//�d�͂��󂯂�
	Player_Dance//�x��
};
class Collision;
class PlayerAction;

//�X�e�[�W��̃v���C���[�̊��N���X
class Player : public Object{
private:
	Collision *collision_;
	PlayerAction *playeraction_[8];
	void Action();//�L�[�̏�Ԃ���v���C���[�̍s�����s��
public :
	StateCharacter player_state_;
	int angle_;//�W�����v���Ă��鎞�ԋy��Jump���̈ړ�����
	Object *carryon_;//�����Ă��镨�̃A�h���X
	Player(float x, float y, float height, float width,Sound* sound);
	void Initialize(IGameStateChanger *statechanger, Collision *collision);
	void Update()override;
	void Draw()override;
	void Clear()override;
	void Retry()override;
	bool CanClear()override;
};