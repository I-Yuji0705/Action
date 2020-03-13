#pragma once
#include "Object.h"
#include "Player.h"

//�N���A�̏����𖞂�����Ԃ�S��������N���X
//���̋�ԓ���ClearZone�ȊO��Object�Ŗ������ƃN���A�ɂȂ�
class ClearArea :public Object {
private:
	std::vector<Object*> players_;
	Collision *collision_;
	bool clearstart_;
public:
	ClearArea(float x, float y, float height, float width,Sound* sound);
	void Initialize(IGameStateChanger *stateChanger, Collision *collision)final;
	void Update()final;
	void Draw()final;
};