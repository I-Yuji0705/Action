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

Player::Player(float x, float y, float height, float width,Sound* sound) : Object(x, y, height, width,sound) {
	graph_handle_ = LoadGraph("Image/Player_2.png");
	quality_ = true;
	vector_ = 1;
	angle_ = 0;
	player_state_ = Player_Air;
}
//�v���C���[�̃{�^�����͂��Ǘ�
void Player::Action() {
	//const float kSpeed = 5.0f;
	if (Keyboard::getInstance()->CheckKey(KEY_INPUT_RIGHT) != 0 && //�E�L�[��������Ă���A
		Keyboard::getInstance()->CheckKey(KEY_INPUT_LEFT) == 0) { //���L�[��������Ă��Ȃ�������
		playeraction_[Player_MoveRight]->Do();//�E�Ɉړ�����
	}
	else if (Keyboard::getInstance()->CheckKey(KEY_INPUT_LEFT) != 0 && //���L�[��������Ă���A
		Keyboard::getInstance()->CheckKey(KEY_INPUT_RIGHT) == 0) { //�E�L�[��������Ă��Ȃ�������
		playeraction_[Player_MoveLeft]->Do();//���Ɉړ�����
	}
	//��L�[����͂��ꂽ�Ƃ�
	if ((Keyboard::getInstance()->CheckKey(KEY_INPUT_UP) == 1 && player_state_ == Player_Land) ||//�v���C���[���n��ɂ���Ƃ���
		(Keyboard::getInstance()->CheckKey(KEY_INPUT_UP) > 1 && angle_ != 0)) {//��L�[����͂������Ă���Ƃ�
		playeraction_[Player_Jump]->Do();
	}
	else if (angle_ != 0) {//��L�[�̓��͂����Ă��Ȃ��Ƃ��A�܂��̓W�����v���ɓ��͂���߂��Ƃ�
		angle_ = 0;//angle��0�ɐݒ肷��
	}
	//Space�L�[����͂����Ƃ�
	if (Keyboard::getInstance()->CheckKey(KEY_INPUT_SPACE) == 1) { 
		////�������̂������Ă���Ȃ�
		if(carryon_ != nullptr)
			playeraction_[Player_Throw]->Do();//Throw������s��
		else
			playeraction_[Player_Pick]->Do();//Pick������s��
	}
	//���L�[����͂����Ƃ��A���������Ă����Ȃ�
	if (Keyboard::getInstance()->CheckKey(KEY_INPUT_DOWN) == 1 && carryon_ != nullptr)
		playeraction_[Player_Put]->Do();//Put������s��
	if (Keyboard::getInstance()->CheckKey(KEY_INPUT_LCONTROL) == 1 || Keyboard::getInstance()->CheckKey(KEY_INPUT_RCONTROL) == 1)
		vector_ *= -1;//�v���C���[�̌����𔽓]
}

void Player::Initialize(IGameStateChanger *statechanger, Collision *collision) {
	Object::Initialize(statechanger, collision);
	this->collision_ = collision; 
	carryon_ = nullptr;
	playeraction_[Player_MoveRight] = new PlayerMoveRight(collision_, this, sound_);
	playeraction_[Player_MoveLeft] = new PlayerMoveLeft(collision_, this, sound_);
	playeraction_[Player_Jump] = new PlayerJump(collision_, this, sound_);
	playeraction_[Player_Throw] = new PlayerThrow(collision_, this, sound_);
	playeraction_[Player_Pick] = new PlayerPick(collision_, this, sound_);
	playeraction_[Player_Put] = new PlayerPut(collision_, this, sound_);
	playeraction_[Player_Gravity] = new PlayerGravity(collision_, this, sound_);
	playeraction_[Player_Dance] = new PlayerDance(collision_, this, sound_);
}
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
void Player::Draw() {
	if(vector_ ==1) DrawModiGraphF(x_, y_, x_ + width_, y_, x_ + width_, y_ + height_, x_, y_ + height_, graph_handle_, TRUE);
	else DrawModiGraphF(x_ + width_, y_, x_, y_, x_, y_ + height_, x_ + width_, y_ + height_, graph_handle_, TRUE);
}

//�N���A�����Ƃ��̏���
void Player::Clear() {
	player_state_ = Player_Clear;
	state_changer_->ChangeState(Game_Dance);
}
//���g���C�����Ƃ��̏���
void Player::Retry() {
	Object::Retry();
	player_state_ = Player_Air;
	vector_ = 1;
}
//�N���A�o���邩��Ԃ�����
//	����:
//		true:�N���A�\
//		false:�N���A�ł��Ȃ�
bool Player::CanClear() {
	bool canclear_ = true;
	if (player_state_ == Game_Clear) {//���łɃN���A���Ă���ꍇ
		canclear_ = false;
	}
	return canclear_;
}