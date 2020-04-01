#include "PlayerMoveX.h"
#include <tuple>
#include "DxLib.h"
#include "Keyboard.h"
#include <vector>
#include <algorithm>
#include "VectorNoduplicationInsert.h"

///<summary>
///<para>�R���X�g���N�^</para>
///<para>�L�[��������Ă��邩�m�F����Keyboard�N���X�A���쎞�ɉ��𔭐�������N���X�A�ړ���ɑ���Object���Ȃ����m�F����N���X�A�ڐG�������s���N���X��ǉ��Ŏ擾����</para>
///<para>����:</para>
///<param name= "keyboard"><para>�L�[��������Ă��邩�m�F����N���X</para></param>
///<param name= "sound"><para>���쎞�ɉ��𔭐�������N���X</para></param>
///<param name= "collision"><para>�E���͈͂ɑ���Object���Ȃ����m�F����N���X</para></param>
///<param name= "playerhit"><para>Player�̐ڐG�������s���N���X</para></param>
///</summary>
PlayerMoveX::PlayerMoveX(Keyboard* keyboard,Sound* sound, Collision *collision, Player *player, PlayerHit* playerhit) : PlayerAction(player) {
	keyboard_ = keyboard;
	sound_ = sound;
	collision_ = collision;
	playerhit_ = playerhit;
	firsthit_ = true;
}

///<summary>
///<para>�s������</para>
///<para>�L�[�{�[�h�̍��E�L�[�̓��͏�Ԃ��m�F���A�ړ����s���B</para>
///<para>���L�[�݂̂������Ă���ꍇ�́A���ړ�����B</para>
///<para>�E�L�[�݂̂������Ă���ꍇ�́A�E�ړ�����B</para>
///</summary>
void PlayerMoveX::Do() {
	if (keyboard_->CheckKey(KEY_INPUT_LEFT) != 0 && //���L�[��������Ă���A
		keyboard_->CheckKey(KEY_INPUT_RIGHT) == 0) { //�E�L�[��������Ă��Ȃ�������
		player_->vector_ = -1;
		MoveX(-kMoveSpeed);
	}
	if (keyboard_->CheckKey(KEY_INPUT_RIGHT) != 0 && //�E�L�[��������Ă���A
		keyboard_->CheckKey(KEY_INPUT_LEFT) == 0) { //���L�[��������Ă��Ȃ�������
		player_->vector_ = 1;
		MoveX(kMoveSpeed);
	}
}
///<summary>
///<para>X���̈ړ�����</para>
///<para>�ړ����悤�Ƃ��Ă��鐔�����󂯎��A�ړ���ɑ���Object�ɐڐG���邩�𒲂ׂ�</para>
///<para>�ړ����Object�Ȃ��ꍇ:x�ɐ��l�����Z���A�ړ�����</para>
///<para>�ړ����Object����ꍇ:�Ώۂ�Object�������A�����������Ȃ�������ڐG�������s��</para>
///<para>Player��Object�������Ă���ꍇ�A����Object�����l�ɐڐG���邩�𒲂ׂ�</para>
///<para>����:</para>
///<param name="num"><para>num:X���ɉ��Z���悤�Ƃ��Ă���l</para></param>
///</summary>
void PlayerMoveX::MoveX(float num) {
	//�v���C���[��X���̈ړ����s��
	bool hit = false;
	int hitpoint;
	float distance;
	std::vector<Object*> hitobjects;
	std::tie(hitpoint, distance, hitobjects) = collision_->HitCheckX(num, player_);//�ړ������ۂɓ�����I�u�W�F�N�g�Ɠ�����ꏊ�̎Z�o
	if (player_->carryon_ != nullptr) {
		player_->carryon_->Update();
		float carryondistance;
		std::vector<Object*> carryonhitobjects;
		int carryonhitpoint;
		std::tie(carryonhitpoint, carryondistance, carryonhitobjects) = collision_->HitCheckX(num, player_->carryon_);//�w�����Ă��镨�̓����蔻����`�F�b�N����
		if (!carryonhitobjects.empty() && carryonhitpoint != 0) {
			hitpoint = carryonhitpoint;
			hitobjects = VectorNoDuplicationInsert(hitobjects, carryonhitobjects);
			if (distance == 999.0f || (std::abs(distance) > std::abs(carryondistance) && carryondistance != 0))
				distance = carryondistance;
		}
	}
	if (hitpoint != 0 && !hitobjects.empty()) {//��������Object����������
		if(!Push(num, hitobjects, hitpoint))//�I�u�W�F�N�g������
			playerhit_->HitObjects(hitpoint, distance);//Hit�������̃v���C���[�̈ʒu�𒲐�����
		if (firsthit_) {//Object�ɐڐG���n�߂��Ƃ�
			sound_->PlaySe(Se_Hit, player_);
			firsthit_ = false;
		}
		hit = true;
	}
	std::tie(hitpoint,distance)= collision_->MapCheck(player_->Left() + num, player_);
	if (hitpoint != 0) {//�}�b�v�O�Ɉړ����Ă��܂����m�F���鏈��
		playerhit_->HitObjects(hitpoint,distance);
		hit = true;
		if (firsthit_) {
			firsthit_ = false;
			sound_->PlaySe(Se_Hit, player_);
		}
	}
	if (!hit) {//�ړ���ɉ����I�u�W�F�N�g���Ȃ��A�}�b�v�O�Ɉړ����Ȃ��ꍇ
		player_->x_ += num;
		firsthit_ = true;
	}
}
///<summary>
///<para>Player�̉�������</para>
///<para>�n�ʂɂ���Ƃ��ɂ̂݁A����������J�n����</para>
///<para>�n���ꂽ���I�z��̂���APlayer�ɖ������Ă���Object�ƁA</para>
///<para>Player�ɖ������Ă��Ȃ�Object�̓��APlayer����߂�Object�Ƃ̍��𓾂���</para>
///<para>Player��Object�������Ă���ꍇ�A���l�ɖ������Ă���Object�Ɩ������Ă��Ȃ�Object�Ƃ̍����擾����</para>
///<para>�������Ă���Object�ɁA�n���ꂽfloat�̒l�ɑ΂��āA�ǂ̒��x�����邩���擾����</para>
///<para>���������l�̂����A��ԏ������l��Player�ɖ������Ă���Object�S�Ă�����</para>
///<para>���ۂɉ��������ǂ�����߂�l�ɂ���</para>
///<para>����:</para>
///<param name="num"><para>num:X���ɉ��Z���悤�Ƃ��Ă���l</para></param>
///<param name="target"><para>target:�������Ƃ��Ă���Ώۂ�Object�̃|�C���^�S��</para></param>
///<param name="check"><para>check:Collision::HitCheckX�ł�int�^�̖߂�l�A�������Ƃ��Ă���������m�F����</para></param>
///<returns>
///<para>true:�����ł��������Ƃ��ł���</para>
///<para>false:�����������Ȃ�����</para>
///</returns>
///</summary>
bool PlayerMoveX::Push(float num, std::vector<Object*> target, int check) {
	bool push = false;
	if (player_->player_state_ == Player_Land) {//�n��ɂ���Ƃ�
		float canpushed;
		std::vector<Object*> pushtarget;
		std::tie(pushtarget, canpushed) = collision_->AlignAdhesionObjects(target, player_, check);
		if (player_->carryon_ != nullptr) {
			float carryoncanpushed;
			std::vector<Object*> carryonpushtarget;
			std::tie(carryonpushtarget, carryoncanpushed) = 
				collision_->AlignAdhesionObjects(target, player_->carryon_, check);
			if (!carryonpushtarget.empty()) {
				pushtarget = VectorNoDuplicationInsert(pushtarget, carryonpushtarget);
				if ((std::abs(canpushed) > std::abs(carryoncanpushed) && carryoncanpushed != 0))
					canpushed = carryoncanpushed;
			}
		}
		if (!pushtarget.empty()) {
			for (auto i : pushtarget) {
				if (std::abs(canpushed) > std::abs(i->CanPushed(num))) {//
					canpushed = i->CanPushed(num);//�����o���鋗�����Z�o
				}
			}
			if (canpushed != 0.0f) {
				for (auto i : pushtarget) {
					i->Pushed(canpushed);
				}
				push = true;
				player_->Set(player_->Left() + canpushed, player_->Top());
				if (player_->carryon_ != nullptr)
					player_->carryon_->Update();
			}
		}
	}
	return push;
}