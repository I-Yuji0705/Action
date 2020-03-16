#include "GraphDeta.h"
#include "DxLib.h"

///<summary>
///<para>コンストラクタ</para>
///<para>表示する場所の左上と右下の座標と画像の取得</para>
///<param name = x1><para>x1:左上のX座標</para></param>
///<param name = y1><para>y1:左上のY座標</para></param>
///<param name = x2><para>x2:右下のX座標</para></param>
///<param name = y2><para>y2:右下のY座標</para></param>
///<param name = graph><para>graph:描写する画像のアドレス(LoadGraph)</para></param>
///</summary>
GraphDeta::GraphDeta(int x1, int y1, int x2, int y2, int graph) {
	x1_ = x1;
	y1_ = y1;
	x2_ = x2;
	y2_ = y2;
	graph_ = graph;
}

///<summary>
///<para>描写処理</para>
///</summary>
void GraphDeta::Draw() {
	DrawModiGraph(x1_, y1_, x2_, y1_, x2_, y2_, x1_, y2_, graph_, TRUE);
}

///<summary>
///<para>終了処理</para>
///<para>画像をメモリ上から削除する</para>
///</summary>
void GraphDeta::Finalize() {
	DeleteGraph(graph_);
}