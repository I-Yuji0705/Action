#pragma once
#include "DrawingDeta.h"
#include <vector>
#include "Keyboard.h"

class DrawingDeta;
class Keyboard;
//SelectionDeta�����Ƃɕ����̍��ڂ�
//�I������\������N���X
class SelectionBase{
protected:
	std::vector<DrawingDeta*> choicedeta_;//�I���������铮�I�z��
	std::vector<DrawingDeta*> drawingdeta_;//�I�����ȊO�����铮�I�z��
	int selectnum_;
	void SelectionColorChange();
	void SelectSelection();
	Keyboard* keyboard_;
public:
	SelectionBase(Keyboard* keyboard);
	virtual void Initialize();//����������
	virtual void Update() {};//�X�V����
	virtual void Draw();//�`�ʏ���
	virtual void Finalize();//�I������
};