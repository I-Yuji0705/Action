#pragma once
#include <vector>
#include "Object.h"
#include "Terrain.h"
#include "Player.h"
#include "Collision.h"

//�Q�[������Player�𒆐S�Ɏʂ����߂ɃX�e�[�W�̒������s���N���X
class Camera {
private:
	Object *map_left_, *map_right_;//�X�e�[�W���[�A�E�[�ɂ���n�`Object
	Object *player_;//���S�Ɏʂ��Ώۂ�Object
	std::vector<Object*> stage_;//�X�e�[�W

public:
	void Initialize(std::vector<Object*> stage, Collision* collision);
	void Update();
};