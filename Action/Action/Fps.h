#pragma once
#include "Singleton.h"

//90Hz�̃��j�^���g�p���Ă���ꍇ�ł��A60Hz�̏ꍇ�Ɠ����悤��������N���X
class Fps : public Singleton<Fps> {
protected:
	Fps();
	friend Singleton<Fps>;
private:
	int start_time_;
	int count_;
public:
	int Update();
};