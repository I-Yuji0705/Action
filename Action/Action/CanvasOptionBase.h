#pragma once
#include "CanvasBase.h"


class OptionDetaBase;
//DrawingDeta�ɉ����āA�I������\������N���X
class CanvasOptionBase : public CanvasBase {
protected:
	std::vector<OptionDetaBase*> optiondeta_;//�I���������铮�I�z��
	int selectnum_;
	void OptionColorChange();
	void OptionUpdate();
public:
	CanvasOptionBase(Keyboard* keyboard);
	virtual void Initialize();//����������
	virtual void Update();//�X�V����
	virtual void Draw();//�`�ʏ���
	virtual void Finalize();//�I������
};