#include "PlayerMoveY.h"
#include <tuple>
#include "DxLib.h"
#include "VectorFunctions.h"

///<summary>
///<para>�R���X�g���N�^</para>
///<para>�L�[��������Ă��邩�m�F����Keyboard�N���X�A���쎞�ɉ��𔭐�������N���X�A�ړ���ɑ���Object���Ȃ����m�F����N���X�A�ڐG�������s���N���X��ǉ��Ŏ擾����</para>
///<param name= "keyboard"><para>�L�[��������Ă��邩�m�F����N���X</para></param>
///<param name= "sound"><para>���쎞�ɉ��𔭐�������N���X</para></param>
///<param name= "collision"><para>�E���͈͂ɑ���Object���Ȃ����m�F����N���X</para></param>
///<param name= "playerhit"><para>Player�̐ڐG�������s���N���X</para></param>
///</summary>
PlayerMoveY::PlayerMoveY(Keyboard* keyboard,Sound* sound, Collision *collision, Player *player, PlayerHit* playerhit) : PlayerAction(player) {
	keyboard_ = keyboard;
	sound_ = sound;
	collision_ = collision;
	playerhit_ = playerhit;
}

///<summary>
///<para>�s������</para>
///<para>��L�[���������ꍇ�A�W�����v����</para>
///<para>�����Ă��Ȃ��ꍇ�A�܂��͏d�͂�����ɏオ��͂��Ȃ��ꍇ�A���ɗ�������</para>
///</summary>
void PlayerMoveY::Do() {
	float jumpdistance = 0.0f;
	if ((keyboard_->CheckKey(KEY_INPUT_UP) == 1 && player_->player_state_ == StateCharacter::Player_Land) ||//�v���C���[���n��ɂ���Ƃ���
		(keyboard_->CheckKey(KEY_INPUT_UP) > 1 && player_->angle_ != 0)) {//��L�[����͂������Ă���Ƃ�
		if (player_->angle_ == 0) sound_->PlaySe(Se_Name::Se_Jump, player_);
		if (player_->angle_ > 60) player_->angle_ = 60;//��L�[����͂������Ă�cos(90 * player_->angle_ / 60 * 3.141592f / 180)��0�ɂȂ�悤�ɂ���
		if (std::abs(kJumpPower * (float)cos(90 * player_->angle_ / 60 * 3.141592f / 180)) > abs(gravity_.kGravity))
			jumpdistance = -kJumpPower * (float)cos(90 * player_->angle_ / 60 * 3.141592f / 180);
		player_->angle_++;//angle�𑝉���������
	}
	else if (player_->angle_ != 0) {//��L�[�̓��͂����Ă��Ȃ��Ƃ��A�܂��̓W�����v���ɓ��͂���߂��Ƃ�
		player_->angle_ = 0;//angle��0�ɐݒ肷��
	}
	jumpdistance += gravity_.kGravity;
	MoveY(jumpdistance);
}

///<summary>
///<para>Y���̈ړ�����</para>
///<para>�ړ����悤�Ƃ��Ă��鐔�����󂯎��A�ړ���ɑ���Object�ɐڐG���邩�𒲂ׂ�</para>
///<para>�ړ���܂���Player�������Ă���Object�ȊO��Object���Ȃ��ꍇ:y�ɐ��l�����Z���A�󒆂Ɉړ�����</para>
///<para>�ړ���܂���Player�������Ă���Object�ȊO�ɂ�Object���������ꍇ:�ڐG�������s��</para>
///<para>Player��Object�������Ă���ꍇ�A����Object�����l��Player�ȊO�ƐڐG���邩�𒲂ׂ�</para>
///<param name="num"><para>num:X���ɉ��Z���悤�Ƃ��Ă���l</para></param>
///</summary>
void PlayerMoveY::MoveY(float num) {
	//�v���C���[��Y���̈ړ����s��
	bool hit = false;
	int hitpoint;
	float distance;
	std::vector<Object*> hitobjects; 
	float carryondistance;
	std::vector<Object*> carryonhitobjects;
	int carryonhitpoint;
	std::tie(hitpoint, distance, hitobjects) = collision_->HitCheckY(num, player_,player_->carryon_);//�ړ������ۂɓ�����I�u�W�F�N�g�Ɠ�����ꏊ�̎Z�o
	if (player_->carryon_ != nullptr) {
		//auto carryon = std::find(hitobjects.begin(), hitobjects.end(), player_->carryon_);
		//if (carryon != hitobjects.end())
		//	hitobjects.erase(carryon);
		std::tie(carryonhitpoint, carryondistance, carryonhitobjects) = collision_->HitCheckY(num, player_->carryon_,player_);//�w�����Ă��镨�̓����蔻����`�F�b�N����
		//auto player = std::find(carryonhitobjects.begin(), carryonhitobjects.end(), player_);
		//if (player != carryonhitobjects.end())
		//	carryonhitobjects.erase(player);
		if (!carryonhitobjects.empty() && carryonhitpoint != 0) {
			hitpoint = carryonhitpoint;
			if ((std::abs(distance) > std::abs(carryondistance) /*&& carryondistance != 0.0f*/))
				distance = carryondistance;
		}
		hitobjects = VectorNoDuplicationInsert(hitobjects, carryonhitobjects);
	}
	if (hitpoint != 0 && !hitobjects.empty()) {//��������Object����������
			playerhit_->HitObjects(hitpoint, distance);//Hit�������̃v���C���[�̈ʒu�𒲐�����
			if (distance != 0.0f || num < 0)
				sound_->PlaySe(Se_Name::Se_Hit, player_);
	}
	else {
		player_->y_ += num;
		player_->player_state_ = StateCharacter::Player_Air;
	}
	if (player_->carryon_ != nullptr)
		player_->carryon_->Update();
}