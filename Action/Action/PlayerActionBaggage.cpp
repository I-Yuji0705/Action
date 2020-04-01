#include "PlayerActionBaggage.h"
#include <tuple>
#include "DxLib.h"

///<summary>
///<para>�R���X�g���N�^</para>
///<para>�L�[��������Ă��邩�m�F����Keyboard�N���X�A�E���͈͂ɑ���Object���Ȃ����m�F����N���X�A�s�����̉����Ǘ�����N���X��ǉ��Ŏ擾����</para>
///<param name= "keyboard"><para>�L�[��������Ă��邩�m�F����N���X</para></param>
///<param name= "sound"><para>���쎞�ɉ��𔭐�������N���X</para></param>
///<param name= "collision"><para>�E���͈͂ɑ���Object���Ȃ����m�F����N���X</para></param>
///</summary>
PlayerActionBaggage::PlayerActionBaggage(Keyboard* keyboard, Sound* sound, Collision *collision, Player *player) : PlayerAction(player) {
	keyboard_ = keyboard;
	collision_ = collision;
	sound_ = sound;
}
///<summary>
///<para>�s������</para>
///<para>�����ꂽ�L�[�ƁAPlayer��Object�������Ă��邩�ǂ����ɂ���čs�����ς��</para>
///<para>Space�L�[�����������APlayer��Object�������Ă����ꍇ:Throw����</para>
///<para>Space�L�[�����������APlayer��Object�������Ă��Ȃ��ꍇ:Pick����</para>
///<para>���L�[���������Ƃ��APlayer��Object�������Ă����ꍇ:Put����</para>
///</summary>
void PlayerActionBaggage::Do() {
	if (keyboard_->CheckKey(KEY_INPUT_SPACE) == 1) {
		////�������̂������Ă���Ȃ�
		if (player_->carryon_ != nullptr)
			Throw();//Throw������s��
		else
			Pick();//Pick������s��
	}
	//���L�[����͂����Ƃ��A���������Ă����Ȃ�
	else if (keyboard_->CheckKey(KEY_INPUT_DOWN) == 1 && player_->carryon_ != nullptr)
		Put();//Put������s��
}

///<summary>
///<para>�E���s������</para>
///<para>player_�̈ʒu�ƌ�������E���͈͂�ݒ肵�A���͈͓̔���Object���������ꍇ�A����Object�ɑ΂��ďE���邩���m�F����</para>
///<para>�E����ꍇ�Aplayer_��carryon�̒l������Object�ɍX�V���A����Object�ɏE��ꂽ���̓�����s�킹��</para>
///</summary>
void PlayerActionBaggage::Pick() {
	Object *goods = nullptr;
	const float krange = player_->GetWidth(); //Item���E���鉡��
	float posx[2];//�E����͈͂̍��[�ƉE�[��X��
	float posy[2];//�E����͈͂̏�[�Ɖ��[��Y��
	posy[0] = player_->Top();
	posy[1] = player_->Base();
	if (player_->vector_ == 1) {
		posx[0] = player_->Right();
		posx[1] = player_->Right() + krange;
	}
	else {
		posx[0] = player_->Left() - krange;
		posx[1] = player_->Left();
	}
	goods = collision_->AreaCheck(goods, posx[0], posy[0], posx[1], posy[1], player_);
	if (goods != nullptr) {
		if (goods->CanPicked(player_)) {
			goods->Picked(player_);
			player_->carryon_ = goods;
			sound_->PlaySe(Se_Pick, player_);
		}
		else {
			sound_->PlaySe(Se_Cant, player_);
		}
	}
}

///<summary>
///<para>������s������</para>
///<para>carryon�ɑ΂��ē������邩���m�F����</para>
///<para>��������ꍇ�Aplayer_��carryon�̒l��nullptr�ɍX�V���A����Object�ɓ�����ꂽ���̓�����s�킹��</para>
///</summary>
void PlayerActionBaggage::Throw() {
	if (player_->carryon_->CanThrew()) {
		player_->carryon_->Threw();
		player_->carryon_ = nullptr;
		sound_->PlaySe(Se_Throw, player_);
	}
	else {
		sound_->PlaySe(Se_Cant, player_);
	}
}
///<summary>
///<para>�u���s������</para>
///<para>carryon�ɑ΂��Ēu���邩���m�F����</para>
///<para>�u����ꍇ�Aplayer_��carryon�̒l��nullptr�ɍX�V���A����Object�ɒu���ꂽ���̓�����s�킹��</para>
///</summary>
void PlayerActionBaggage::Put() {
	if (player_->carryon_->CanPutted()) {
		player_->carryon_->Putted();
		player_->carryon_ = nullptr;
		sound_->PlaySe(Se_Put, player_);
	}
	else {
		sound_->PlaySe(Se_Cant, player_);
	}
}