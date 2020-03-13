#pragma once
#include "Object.h"
#include "Player.h"

//�N���A�̏����𖞂�����Ԃ�S��������N���X
//���̋�ԓ���ClearZone�ȊO��Object�Ŗ������ƃN���A�ɂȂ�
class ClearArea :public Object {
private:
	IGameStateChanger *state_changer_;
	Sound* sound_;
	std::vector<Object*> players_;
	Collision *collision_;
	bool clearstart_;
public:
	ClearArea(Sound* sound, IGameStateChanger* statechanger, Collision* collision, float x, float y, float height, float width);
	void Initialize()final;
	void Update()final;
	void Draw()final;
};