#pragma once
#include "DrawingDeta.h"

//‰æ‘œ‚ð•\Ž¦‚·‚é‚½‚ß‚ÌƒNƒ‰ƒX
class GraphDeta : public DrawingDeta{
private:
	int x1_;
	int y1_;
	int x2_;
	int y2_;
	int graph_;
public:
	GraphDeta(int x1, int y1, int x2, int y2, int graph);
	void Draw() final;
	void Finalize() final;
};