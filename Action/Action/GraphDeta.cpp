#include "GraphDeta.h"
#include "DxLib.h"

GraphDeta::GraphDeta(int x1, int y1, int x2, int y2, int graph) {
	x1_ = x1;
	y1_ = y1;
	x2_ = x2;
	y2_ = y2;
	graph_ = graph;
}

void GraphDeta::Draw() {
	DrawModiGraph(x1_, y1_, x2_, y1_, x2_, y2_, x1_, y2_, graph_, TRUE);
}
void GraphDeta::Finalize() {
	DeleteGraph(graph_);
}