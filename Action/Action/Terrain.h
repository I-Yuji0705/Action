#pragma once
#include "Object.h"

//�X�e�[�W�Œn�`��S��������N���X
class Terrain :public Object {
public:
	Terrain(float x, float y, float height, float width,Sound* sound);
	void Initialize(IGameStateChanger *stateChanger, Collision *collision);//����������
	void Draw() override;
};