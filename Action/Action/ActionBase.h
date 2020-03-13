#pragma once
#include "Object.h"
#include "Collision.h"
#include "Sound.h"

//�Q�[������Object���s���s���̊��N���X
class ActionBase {
protected:
	Collision* collision_;//�A�N�V�������̕���������v������ꏊ
	Sound* sound_;//�A�N�V�������ɖ炷��
public:
	ActionBase(Collision* collision,Sound* sound);
	virtual void Do() = 0;//�A�N�V�������N����
};