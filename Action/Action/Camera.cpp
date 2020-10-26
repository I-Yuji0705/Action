#include "Camera.h"
#include "DxLib.h"
#include <typeinfo>


///<summary>
///<para>�R���X�g���N�^</para>
///<para>�`�ʂ���X�e�[�W��Cpllision�N���X�̃|�C���^�̎擾</para>
///<para>state:�`�ʂ���X�e�[�W�̃|�C���^</para>
///<para>collision:�v���C���[�ƃX�e�[�W�E�[�A���[�I�u�W�F�N�g�̃|�C���^��Ⴄ</para>
///</summary>
Camera::Camera(std::vector<Object*>* stage, Collision* collision) {
	stage_ = stage;
	collision_ = collision;
}

///<summary>
///<para>����������</para>
///<para>�X�e�[�W�̉E�[�A���[�A��ʂ̒����ɕ`�ʂ���Player�̃|�C���^�̎擾</para>
///</summary>
void Camera::Initialize() {
	map_left_ = collision_->GetMapLeft(map_left_);
	map_right_ =  collision_->GetMapRight(map_right_);
	player_ = *collision_->GetPlayer().begin();//���S�ɕ`�ʂ���Player�̐ݒ�
}

///<summary>
///<para>�X�V����</para>
///<para>player���X�e�[�W�E�[�A���[�ɂ���ꍇ�������āA��ʂ̒����ɕ`�ʂ���悤�ɑS�̂𓮂���</para>
///</summary>
void Camera::Update(){
	float distance = 0;//Player�Ɖ�ʒ����Ƃ̍�
	const float kWindowX = 640.0f;//��ʂ̉���
	if (player_->Center_X() != kWindowX / 2) {
		distance = (player_->Right() + player_->Left()) / 2 - kWindowX / 2;
	}	
	if (distance < 0 && map_left_->Left() < 0) {
		if (map_left_->Left() - distance > 0) distance = map_left_->Left();
		for (auto i : *stage_) {
			i->Set(i->Left() - distance,i->Top());//�I�u�W�F�N�g�̍Đݒu
		}
	}
	if (distance > 0 && map_right_->Right() > kWindowX) {
		if (map_right_->Right() - distance < kWindowX) distance = map_right_->Right() - kWindowX;
		for (auto i : *stage_) {
			i->Set(i->Left() - distance, i->Top());//�I�u�W�F�N�g�̍Đݒu
		}
	}
}