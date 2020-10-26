#include "Player.h"
#include "DxLib.h"
#include "Keyboard.h"
#include "PlayerActionBaggage.h"
#include "PlayerDance.h"
#include "PlayerMoveX.h"
#include "PlayerMoveY.h"
#include "PlayerInversion.h"

///<summary>
///<para>�R���X�g���N�^</para>
///<para>�`�ʂ���摜�̐ݒ�A����������̏������s���N���X�A�s�����Ǘ�����N���X�̐���</para>
///<param name= "sound"><para>���쎞�ɉ��𔭐�������N���X</para></param>
///<param name= "collision"><para>���쎞�⓮��m�F���ɐڐG����𒲂ׂ�</para></param>
///</summary>
Player::Player(Keyboard* keyboard,Sound* sound, IGameStateChanger* statechanger,Collision* collision,float x, float y, float height, float width) : Object(x, y, height, width) {
	sound_ = sound; 
	state_changer_ = statechanger;
	collision_ = collision;
	graph_handle_ = LoadGraph("Image/Player_2.png");
	quality_ = true;
	angle_ = 0;
	carryon_ = nullptr;
	player_state_ = StateCharacter::Player_Air;
	playerhit_ = new PlayerHit(collision_,this);
	playeraction_[static_cast<int>(PlayerActionList::Player_MoveX)] = new PlayerMoveX(keyboard, sound_, collision_, this, playerhit_);//���E�Ɉړ�����
	playeraction_[static_cast<int>(PlayerActionList::Player_MoveY)] = new PlayerMoveY(keyboard, sound_, collision_, this, playerhit_);//�㉺�Ɉړ�����
	playeraction_[static_cast<int>(PlayerActionList::Player_Baggage)] = new PlayerActionBaggage(keyboard, sound_, collision_, this);//Item�ɑ΂��ẴA�N�V����
	playeraction_[static_cast<int>(PlayerActionList::Player_Inversion)] = new PlayerInversion(keyboard, this);//�������]
	playeraction_[static_cast<int>(PlayerActionList::Player_Dance)] = new PlayerDance(this);
}

///<summary>
///<para>�v���C���[�̃A�N�V�����̊Ǘ�</para>
///<para>�v���C���[�̃L�[���͂Ƃ���ɑΉ�����PlayerAction���s��</para>
///</summary>
void Player::Action() {
	playeraction_[static_cast<int>(PlayerActionList::Player_MoveY)]->Do();//�㉺�Ɉړ�����
	playeraction_[static_cast<int>(PlayerActionList::Player_MoveX)]->Do();//�㉺�Ɉړ�����
	playeraction_[static_cast<int>(PlayerActionList::Player_Baggage)]->Do();//Item�ɑ΂��ẴA�N�V����
	playeraction_[static_cast<int>(PlayerActionList::Player_Inversion)]->Do();//�������]
}

///<summary>
///<para>����������</para>
///</summary>
void Player::Initialize() {
	carryon_ = nullptr;
	vector_ = 1;
	angle_ = 0;
	player_state_ = StateCharacter::Player_Air;
}

///<summary>
///<para>�X�V����</para>
///<para>Player��state���N���A��Ԃ̎��̂݁ADance�������s��</para>
///</summary>
void Player::Update() {
	switch (player_state_) {
	case StateCharacter::Player_Clear:
		playeraction_[static_cast<int>(PlayerActionList::Player_Dance)]->Do();
		break;
	default:
		Action();
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
	player_state_ = StateCharacter::Player_Clear;
	state_changer_->ChangeState(GameState::Game_Dance);
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
	if (player_state_ == StateCharacter::Player_Clear) {//���łɃN���A���Ă���ꍇ
		canclear_ = false;
	}
	return canclear_;
}