#pragma once

//90Hzのモニタを使用している場合でも、60Hzの場合と同じよう調整するクラス
class Fps {
private:
	int start_time_;
	int count_;
public:
	Fps();
	int Update();
};