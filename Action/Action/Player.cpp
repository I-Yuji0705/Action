#include "Player.h"
#include "DxLib.h"
#include "Keyboard.h"
#include "PlayerMoveRight.h"
#include "PlayerMoveLeft.h"
#include "PlayerJump.h"
#include "PlayerThrow.h"
#include "PlayerPick.h"
#include "PlayerPut.h"
#include "PlayerGravity.h"
#include "PlayerDance.h"

///<summary>
///<para>�R���X�g���N�^</para>
///<para>�`�ʂ���摜�̐ݒ�A����������̏������s���N���X�A�s�����Ǘ�����N���X�̐���</para>
///<para>����:</para>
///<param name= "sound"><para>���쎞�ɉ��𔭐�������N���X</para></param>
///<param name= "collision"><para>���쎞�⓮��m�F���ɐڐG����𒲂ׂ�</para></param>
///</summary>
Player::Player(Keyboard* keyboard,Sound* sound, IGameStateChanger* statechanger,Collision* collision,float x, float y, float height, float width) : Object(x, y, height, width) {
	keyboard_ = keyboard;
	sound_ = sound; 
	state_changer_ = statechanger;
	collision_ = collision;
	graph_handle_ = LoadGraph("Image/Player_2.png");
	quality_ = true;
	playerhit_ = new PlayerHit(collision_,this);
	playeraction_[Player_MoveRight] = new PlayerMoveRight(sound_,collision_, this,playerhit_);
	playeraction_[Player_MoveLeft] = new PlayerMoveLeft(sound_, collision_, this, playerhit_);
	playeraction_[Player_Jump] = new PlayerJump(sound_, collision_, this, playerhit_);
	playeraction_[Player_Throw] = new PlayerThrow(sound_,this);
	playeraction_[Player_Pick] = new PlayerPick(sound_, collision_,this);
	playeraction_[Player_Put] = new PlayerPut(sound_,this);
	playeraction_[Player_Gravity] = new PlayerGravity(sound_, collision_, this, playerhit_);
	playeraction_[Player_Dance] = new PlayerDance(this);
}

///<summary>
///<para>�v���C���[�̃A�N�V�����̊Ǘ�</para>
///<para>�v���C���[�̃L�[���͂Ƃ���ɑΉ�����PlayerAction���s��</para>
///</summary>
void Player::Action() {
	if (keyboard_->CheckKey(KEY_INPUT_RIGHT) != 0 && //�E�L�[��������Ă���A
		keyboard_->CheckKey(KEY_INPUT_LEFT) == 0) { //���L�[��������Ă��Ȃ�������
		playeraction_[Player_MoveRight]->Do();//�E�Ɉړ�����
	}
	else if (keyboard_->CheckKey(KEY_INPUT_LEFT) != 0 && //���L�[��������Ă���A
		keyboard_->CheckKey(KEY_INPUT_RIGHT) == 0) { //�E�L�[��������Ă��Ȃ�������
		playeraction_[Player_MoveLeft]->Do();//���Ɉړ�����
	}
	//��L�[����͂��ꂽ�Ƃ�
	if ((keyboard_->CheckKey(KEY_INPUT_UP) == 1 && player_state_ == Player_Land) ||//�v���C���[���n��ɂ���Ƃ���
		(keyboard_->CheckKey(KEY_INPUT_UP) > 1 && angle_ != 0)) {//��L�[����͂������Ă���Ƃ�
		playeraction_[Player_Jump]->Do();
	}
	else if (angle_ != 0) {//��L�[�̓��͂����Ă��Ȃ��Ƃ��A�܂��̓W�����v���ɓ��͂���߂��Ƃ�
		angle_ = 0;//angle��0�ɐݒ肷��
	}
	//Space�L�[����͂����Ƃ�
	if (keyboard_->CheckKey(KEY_INPUT_SPACE) == 1) { 
		////�������̂������Ă���Ȃ�
		if(carryon_ != nullptr)
			playeraction_[Player_Throw]->Do();//Throw������s��
		else
			playeraction_[Player_Pick]->Do();//Pick������s��
	}
	//���L�[����͂����Ƃ��A���������Ă����Ȃ�
	if (keyboard_->CheckKey(KEY_INPUT_DOWN) == 1 && carryon_ != nullptr)
		playeraction_[Player_Put]->Do();//Put������s��
	if (keyboard_->CheckKey(KEY_INPUT_LCONTROL) == 1 || keyboard_->CheckKey(KEY_INPUT_RCONTROL) == 1)
		vector_ *= -1;//�v���C���[�̌����𔽓]
}

///<summary>
///<para>����������</para>
///</summary>
void Player::Initialize() {
	carryon_ = nullptr;
	vector_ = 1;
	angle_ = 0;
	player_state_ = Player_Air;
}

///<summary>
///<para>�X�V����</para>
///<para>Player��state���N���A��Ԃ̎��̂݁ADance�������s��</para>
///</summary>
void Player::Update() {
	switch (player_state_) {
	case Player_Clear:
		playeraction_[Player_Dance]->Do();
		break;
	default:
		Action();
		playeraction_[Player_Gravity]->Do();
		break;
	}
}

///<summary>
///<para>�`�ʏ���</para>
///<para>Player�̌����ɂ���āA�`�ʂ���摜�𔽓]����</para>
///</summary>
void Player::Draw() {
	if(vector_ ==1) DrawModiGraphF(x_, y_, x_ + width_, y_, x_ + width_, y_ + height_, x_, y_ + height_, graph_handle_, TRUE);
	else DrawModiGraphF(x_ + width_, y_, x_, y_, x_, y_ + height_, x_ + width_, y_ + height_, graph_handle_, TRUE);
}

///<summary>
///<para>�N���A����</para>
///<para>�N���A�����𖞂������ۂɁA��x�����Ă΂��֐�</para>
///</summary>
void Player::Clear() {
	player_state_ = Player_Clear;
	state_changer_->ChangeState(Game_Dance);
}

///<summary>
///<para>���g���C����</para>
///<para>Object�̃��g���C�����ɉ����A���������s��</para>
///</summary>
void Player::Retry() {
	Object::Retry();
	Initialize();
}

///<summary>
///<para>���N���A�ł��邩��Ԃ�</para>
///<returns>
///<para>true:���������邱�Ƃ��ł���</para>
///<para>false:�����𓊂��邱�Ƃ��ł��Ȃ�</para>
///</returns>
///</summary>
bool Player::CanClear() {
	bool canclear_ = true;
	if (player_state_ == Game_Clear) {//���łɃN���A���Ă���ꍇ
		canclear_ = false;
	}
	return canclear_;
}