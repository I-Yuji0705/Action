#include "Terrain.h"
#include "DxLib.h"

Terrain::Terrain(float x, float y, float height, float width) : Object(x ,y ,height ,width) {
	quality_ = true;//�n�`�̐ڐG�����K�p����
}
//�`�ʏ���
void Terrain::Draw() {
	DrawBoxAA(x_, y_, x_ + width_,  y_ + height_,GetColor(0,0,0), TRUE);//Float�^�̎l�_�̍��W����O�g��`��
}