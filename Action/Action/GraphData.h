#pragma once
#include "DrawingData.h"

//画像を表示するためのクラス
class GraphData : public DrawingData{
private:
	int x1_;
	int y1_;
	int x2_;
	int y2_;
	int graph_;
public:
	GraphData(int x1, int y1, int x2, int y2, int graph);
	void Draw() final;
	void Finalize() final;
};