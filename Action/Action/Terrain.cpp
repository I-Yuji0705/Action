#include "Terrain.h"
#include "DxLib.h"
//Object��Set�����ɉ����Aobject_number�ɂ���ĕ`�ʂ���摜��ύX����
Terrain::Terrain(float x, float y, float height, float width, int object_number) : Object(x ,y ,height ,width ,object_number ) {
	switch (this->object_number_) {
	case 0:
		//graph_handle_ = LoadGraph("Image/Terrain.png");
		quality_ = true;
		damegeflg_ = false;
		break;
	default:
		break;
	}
}
void Terrain::Draw() {
	DrawBoxAA(x_, y_, x_ + width_,  y_ + height_,GetColor(0,0,0), TRUE);//Float�^�̎l�_�̍��W����O�g��`��
	float distance = 5.0f;//�n�`�̊O���Ɠ����̍�
	//DrawBoxAA(x_ + distance, y_ + distance, x_ + width_ - distance, y_ + height_ - distance, GetColor(255,255,255), TRUE);//Float�^�̎l�_�̍��W�Ƃ��̍����������`��
}