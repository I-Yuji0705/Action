#pragma once
#include "Object.h"
#include "Collision.h"
#include "Sound.h"

//�Q�[������Object���s���s���̊��N���X
class IActionBase {
protected:
public:
	virtual void Do() = 0;//�A�N�V�������N����
};