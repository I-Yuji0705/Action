#include "Terrain.h"
#include "DxLib.h"

///<summary>
///<para>�R���X�g���N�^</para>
///<para>�ǉ��ŐڐG����̏��������s��</para>
///</summary>
Terrain::Terrain(float x, float y, float height, float width) : Object(x ,y ,height ,width) {
	quality_ = true;//�ڐG�����K�p����
}

///<summary>
///<para>�`�ʏ���</para>
///<para>�n�`�͈̔͂����F�ŕ���</para>
///</summary>
void Terrain::Draw() {
	DrawBoxAA(x_, y_, x_ + width_,  y_ + height_,GetColor(0,0,0), TRUE);//Float�^�̎l�_�̍��W����O�g��`��
}