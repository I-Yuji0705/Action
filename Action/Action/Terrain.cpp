#include "Terrain.h"
#include "DxLib.h"

Terrain::Terrain(float x, float y, float height, float width,Sound* sound) : Object(x ,y ,height ,width,sound) {
	quality_ = true;//�n�`�̐ڐG�����K�p����
}
//�`�ʏ���
void Terrain::Draw() {
	DrawBoxAA(x_, y_, x_ + width_,  y_ + height_,GetColor(0,0,0), TRUE);//Float�^�̎l�_�̍��W����O�g��`��
}
//-------
//����������
//�����s��Ȃ�
void Terrain::Initialize(IGameStateChanger *stateChanger, Collision *collision) {
}