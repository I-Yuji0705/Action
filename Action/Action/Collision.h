#pragma once
#include <vector>
#include <tuple>
#include "Object.h"

//�X�e�[�W��̃I�u�W�F�N�g���m�̐ڐG����ƁA�X�e�[�W��̃I�u�W�F�N�g�̏���Ԃ��N���X
class Object;
class Collision {
private:
	std::vector<Object *> stage_;
	Object *map_right_, *map_left_;
	bool Check(float x1, float y1, float x2, float y2, const Object* player,const Object* object);
	bool Check(float x, float y, const Object* player,const Object* object);
public:
	Collision(std::vector<Object*> stage);
	bool Check(float x, float y, const Object *player);
	std::tuple<int, std::vector<Object*>> HitCheckX(float num, const Object* player);//point����num��ǉ������ہA����object�ɓ����邩�A�ǂ̕����ɓ�����������Ԃ�
	std::tuple<int, std::vector<Object*>> HitCheckY(float num, const Object* player);//point����num��ǉ������ہA����object�ɓ����邩�A�ǂ̕����ɓ�����������Ԃ�
	int MapCheck(float x,const Object* player);
	int PointCheck(float x, float y,const Object *player);
	bool AreaFullCheck(const Object *area);
	Object* AreaCheck(Object* target,float x1,float y1,float x2,float y2,const Object* player);
	Object* GetMapLeft(Object* target);
	Object* GetMapRight(Object* target);
	std::vector<Object*> GetPlayer();
};