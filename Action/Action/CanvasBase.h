#pragma once
#include "DrawingDeta.h"
#include <vector>
#include "Keyboard.h"
#include "OptionDetaBase.h"

class DrawingDeta;
class Keyboard;
//DrawingDeta�����Ƃɕ����̍��ڂ�\������N���X
class CanvasBase{
protected:
	std::vector<DrawingDeta*> drawingdeta_;//�I�����ȊO�����铮�I�z��
	Keyboard* keyboard_;
public:
	CanvasBase(Keyboard* keyboard);
	virtual void Initialize() {};//����������
	virtual void Update() {};//�X�V����
	virtual void Draw();//�`�ʏ���
	virtual void Finalize();//�I������
};