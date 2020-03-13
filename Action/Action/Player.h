#pragma once
#include "Object.h"
#include "Terrain.h"
#include "Collision.h"
#include "PlayerAction.h"
#include "Keyboard.h"
#include "PlayerHit.h"
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
class Keyboard;
class Sound;
class Collision;

//�X�e�[�W��̃v���C���[�̊��N���X
class Player : public Object{
private:
	Keyboard* keyboard_;
	Sound* sound_;
	Collision *collision_;
	PlayerAction *playeraction_[8];
	void Action();//�L�[�̏�Ԃ���v���C���[�̍s�����s��
	PlayerHit* playerhit_;
public :
	IGameStateChanger *state_changer_;
	StateCharacter player_state_;
	int angle_;//�W�����v���Ă��鎞�ԋy��Jump���̈ړ�����
	Object *carryon_;//�����Ă��镨�̃A�h���X
	Player(Keyboard* keyboard,Sound* sound,IGameStateChanger* statechanger,Collision* collision,float x, float y, float height, float width);
	void Initialize()override;
	void Update()override;
	void Draw()override;
	void Clear()override;
	void Retry()override;
	bool CanClear()override;
};