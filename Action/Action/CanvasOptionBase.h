#pragma once
#include "CanvasBase.h"


class OptionDataBase;
//DrawingData�ɉ����āA�I������\������N���X
class CanvasOptionBase : public CanvasBase {
protected:
	std::vector<OptionDataBase*> optionData_;//�I���������铮�I�z��
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