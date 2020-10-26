#include "ClearArea.h"
#include <typeinfo>
#include "DxLib.h"

///<summary>
///<para>�R���X�g���N�^</para>
///<param name="sound"><para>sound:�N���A���̉��y��炷�N���X�̃|�C���^</para></param>
///<param name="collision"><para>collision:�N���A������s���N���X�̃|�C���^</para></param>
///<param name="color"><para>color:�X�e�[�W�w�i�̃J���[�R�[�h</para></param>
///</summary>
ClearArea::ClearArea(Sound* sound,Collision* collision,ColorCode color,float x, float y, float height, float width) : Object(x, y, height, width) {
	sound_ = sound; 
	collision_ = collision;
	color_ = GetColor(color.Red / 2, color.Green / 2, color.Blue / 2);
	quality_ = false;//�����蔻����Ȃ���
}

///<summary>
///<para>����������</para>
///<para>�v���C���[�̃|�C���^�̎擾</para>
///</summary>
void ClearArea::Initialize() {
	players_ = collision_->GetPlayer();
}

///<summary>
///<para>�X�V����</para>
///<para>����Object��������Object�Ŗ�������Ă��邩���m�F����</para>
///<para>��������Ă���ꍇ�A���y��炵�Aplayer�ɃN���A���̏������s�킹��</para>
///</summary>
void ClearArea::Update() {
	if (collision_->AreaFullCheck(this) ) {
		bool canclear = true;
		for (auto i : players_) {
			if (!i->CanClear()) {
				canclear = false;
				break;
			}
		}
		if (canclear) {
			for (auto i : players_) {
				i->Clear();
			}
		sound_->StopBgm();//�N���A���̉��y��炷���߁Abgm���~�߂�
		sound_->PlaySe(Se_Name::Se_Clear);
		}
	}
}

///<summary>
///<para>�`�ʏ���</para>
///<para>����Object��������Object�Ŗ�������Ă��邩���m�F����</para>
///<para>��������Ă���ꍇ�A���y��炵�Aplayer�ɃN���A���̏������s�킹��</para>
///</summary>
void ClearArea::Draw() {
	DrawBoxAA(x_, y_, x_ + width_, y_ + height_,color_, TRUE);//Float�^�̎l�_�̍��W����O�g��`��
}