#pragma once

//90Hz�̃��j�^���g�p���Ă���ꍇ�ł��A60Hz�̏ꍇ�Ɠ����悤��������N���X
class Fps {
private:
	int start_time_;
	int count_;
public:
	Fps();
	int Update();
};