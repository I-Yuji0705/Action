#pragma once
#include "Object.h"
#include "Collision.h"
#include "Sound.h"

//�Q�[������Object���s���s���̃C���^�[�t�F�[�X�N���X
class IActionBase {
protected:
public:
	virtual ~IActionBase() = 0;
	virtual void Do() = 0;//�A�N�V�������N����
};