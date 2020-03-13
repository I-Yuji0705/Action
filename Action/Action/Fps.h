#pragma once
#include "Singleton.h"
class Fps : public Singleton<Fps> {
protected:
	Fps();
	friend Singleton<Fps>;
private:
	int startTime;
	int count;
public:
	int Update();
};