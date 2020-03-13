#pragma once
#include "Object.h"
#include "Player.h"
#include "ItemAction.h"
#include "IMenuStateChanger.h"
enum ItemState {
	Item_Normal,//Item�̒ʏ���
	Item_Picked,//Item���E���Ă�����
	Item_Throw,//Item���������Ă�����
};
enum ItemActionList {
	Item_Baggage,//������Ă���
	Item_StartThrow,//�������n�߂�
	Item_Threw,//�������Ă���
	Item_Putted,//�u���ꂽ
	Item_Gravity//�d�͂��󂯂Ă���
};
class Collision;
class ItemAction;
class ItemHit;

//�X�e�[�W���Player�������グ����Item�̊��N���X
class Item : public Object {
private:
	Sound* sound_;
	Collision *collision_;
	ItemHit* itemhit_;
	ItemAction *itemaction_[5];//Item�̍s�����s���N���X�z��
public:
	Item(Sound* sound,Collision* collision,float x, float y, float height, float width);
	ItemState state_;
	Object *carrier_;
	void Initialize()override;
	void Update()override;
	void Draw()override;
	float CanPushed(float num)override;
	void Pushed(float num)override;
	bool CanPicked(const Object *object)override;
	void Picked( Object *object)override;
	bool CanPutted()override;
	void Putted()override;
	bool CanThrew()override;
	void Threw()override;
	void Retry()override;
};