#include "GraphDeta.h"
#include "DxLib.h"

///<summary>
///<para>�R���X�g���N�^</para>
///<para>�\������ꏊ�̍���ƉE���̍��W�Ɖ摜�̎擾</para>
///<param name = x1><para>x1:�����X���W</para></param>
///<param name = y1><para>y1:�����Y���W</para></param>
///<param name = x2><para>x2:�E����X���W</para></param>
///<param name = y2><para>y2:�E����Y���W</para></param>
///<param name = graph><para>graph:�`�ʂ���摜�̃A�h���X(LoadGraph)</para></param>
///</summary>
GraphDeta::GraphDeta(int x1, int y1, int x2, int y2, int graph) {
	x1_ = x1;
	y1_ = y1;
	x2_ = x2;
	y2_ = y2;
	graph_ = graph;
}

///<summary>
///<para>�`�ʏ���</para>
///</summary>
void GraphDeta::Draw() {
	DrawModiGraph(x1_, y1_, x2_, y1_, x2_, y2_, x1_, y2_, graph_, TRUE);
}

///<summary>
///<para>�I������</para>
///<para>�摜���������ォ��폜����</para>
///</summary>
void GraphDeta::Finalize() {
	DeleteGraph(graph_);
}