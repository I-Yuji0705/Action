#pragma once

//���ڂ�摜��\�����钊�ۃN���X
class DrawingDeta {
public:
	virtual void Draw() = 0;
	virtual void ChangeColor(unsigned int color) {};
	virtual void Finalize() {};
};