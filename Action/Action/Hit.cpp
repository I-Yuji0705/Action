#include "Hit.h"

///<summary>
///<para>�R���X�g���N�^</para>
///<para>�X�e�[�W�̗��[�̒n�`����������</para>
///</summary>
Hit::Hit(Collision *collision) {
	map_left_ = collision->GetMapLeft(map_left_);
	map_right_ = collision->GetMapRight(map_right_);
}