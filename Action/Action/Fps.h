#pragma once
#include "Singleton.h"
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