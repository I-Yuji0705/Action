#include "Camera.h"
#include "DxLib.h"
#include <typeinfo.h>

//----------------------------------------------------
//Camera�̏������������s���ꏊ
//�X�e�[�W�E�[�A���[��Terrain�A������Player����������
//	����:
//		stage:�X�e�[�W��ɂ���object��vector�z��
//		collision:�v���C���[�ƃX�e�[�W�E�[�A���[��
//					  �I�u�W�F�N�g�̃|�C���^��n��
void Camera::Initialize(std::vector<Object*> stage,Collision* colllision) {
	stage_ = stage;
	map_left_ = colllision->GetMapLeft(map_left_);
	map_right_ =  colllision->GetMapRight(map_right_);
	player_ = *colllision->GetPlayer().begin();//���S�ɕ`�ʂ���Player�̐ݒ�
}
//----------------------------------------------------
//Camera�̍X�V����
//Player���X�e�[�W�E�[�A���[�ɂ���ꍇ�������āA��ʂ̒����ɕ`�ʂ���悤�ɑS�̂𓮂���
void Camera::Update(){
	float distance = 0;//Player�Ɖ�ʒ����Ƃ̍�
	const float kWindowX = 640.0f;//��ʂ̉���
	if (player_->Center_X() != kWindowX / 2) {
		distance = (player_->Right() + player_->Left()) / 2 - kWindowX / 2;
	}	
	if (distance < 0 && map_left_->Left() < 0) {
		if (map_left_->Left() - distance > 0) distance = map_left_->Left();
		for (auto i : stage_) {
			i->Set(i->Left() - distance,i->Top());//�I�u�W�F�N�g�̍Đݒu
		}
	}
	if (distance > 0 && map_right_->Right() > kWindowX) {
		if (map_right_->Right() - distance < kWindowX) distance = map_right_->Right() - kWindowX;
		for (auto i : stage_) {
			i->Set(i->Left() - distance, i->Top());//�I�u�W�F�N�g�̍Đݒu
		}
	}
}