#pragma once
#include "Singleton.h"

//90Hzのモニタを使用している場合でも、60Hzの場合と同じよう調整するクラス
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