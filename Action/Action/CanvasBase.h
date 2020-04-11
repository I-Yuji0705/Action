#pragma once
#include "DrawingData.h"
#include <vector>
#include "Keyboard.h"
#include "OptionDataBase.h"

class DrawingData;
class Keyboard;
//DrawingData�����Ƃɕ����̍��ڂ�\������N���X
class CanvasBase{
protected:
	std::vector<DrawingData*> drawingData_;//�I�����ȊO�����铮�I�z��
	Keyboard* keyboard_;
public:
	CanvasBase(Keyboard* keyboard);
	virtual void Initialize() {};//����������
	virtual void Update() {};//�X�V����
	virtual void Draw();//�`�ʏ���
	virtual void Finalize();//�I������
};