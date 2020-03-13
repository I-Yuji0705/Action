#pragma once
#include <vector>
#include "Object.h"
#include "Terrain.h"
#include "Player.h"
#include "Collision.h"

class Collision;
class Object;

//�Q�[������Player�𒆐S�Ɏʂ����߂ɃX�e�[�W�̒������s���N���X
class Camera {
private:
	Collision* collision_;
	Object *map_left_, *map_right_;//�X�e�[�W���[�A�E�[�ɂ���n�`Object
	Object *player_;//���S�Ɏʂ��Ώۂ�Object
	std::vector<Object*>* stage_;//�X�e�[�W
public:
	Camera(std::vector<Object*>* stage, Collision* collision);
	void Initialize();
	void Update();
};