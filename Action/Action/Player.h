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
	Player_MoveX,//���E�ړ�
	Player_MoveY,//�㉺�ړ�(�������܂�)
	Player_Baggage,//Item�����A�u���A������
	Player_Inversion,//�����𔽓]����
	Player_Dance,//�x��

	Player_ActionNum//Player��Action�̍��v
};
class Collision;
class PlayerAction;
class Keyboard;
class Sound;
class Collision;
class PlayerHit;
//�X�e�[�W��̃v���C���[�̊��N���X
class Player : public Object{
private:
	Sound* sound_;
	Collision *collision_;
	PlayerAction *playeraction_[Player_ActionNum];
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