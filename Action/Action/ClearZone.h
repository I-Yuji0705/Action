#pragma once
#include "Object.h"
#include "Player.h"
//�N���A�̏����𖞂������
//���̋�ԓ���ClearZone�ȊO��Object�Ŗ������ƃN���A�ɂȂ�
class ClearZone :public Object {
private:
	const float minLength = 50.0f;//���̃Q�[���ɂ�����Object�̍ŏ��̒���
	Object *player_;
	bool ClearCheck();
	bool ZoneCheck(float x, float y);
	int ZoneCheck_Y(float x, float y);
	void Clear();
public:
	ClearZone(float x, float y, float height, float width, int object_number);
	void Initialize(IStateChanger *stateChanger, std::vector<Object*>&stage)override;
	void Update()override;
	void Draw() override;
};