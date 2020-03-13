#include "ClearZone.h"
#include <typeinfo.h>
#include "DxLib.h"
//クリアした際に、ClearZoneの周辺にクリアした際の演出の追加
bool ClearZone::ClearCheck() {
	bool check = true;
	const int permissibleLength = 5;//多少ずれてても大丈夫な長さ
	for (int i = (int)this->Left() + permissibleLength; i < (int)this->Right() - permissibleLength; i++) {
		for (int j =(int)this->Top() + permissibleLength; j < (int)this->Base() - permissibleLength; j++) {
			if (ZoneCheck_Y((float)i, (float)j) == 0) {
				check = false;
				break;
			}
			else {
				j += ZoneCheck_Y((float)i, (float)j);
			}
		}
	}
	return check;
}
bool ClearZone::ZoneCheck(float x, float y) {
	bool check = false;
	for (auto i : (*stage_)) {
		if (i->Left() <= x && x <= i->Right() &&
			i->Top() <= y && y <= i->Base()) {
			check = true;
			break;
		}
	}
	return check;
}
//-------------
//選択した引数の座標地点にObjectがあるかどうか、あった場合はy座標からどの程度の高さかを返す
//	引数::x-->座標のx地点
//		  y-->座標のy地点
//	返り値::0-->Objectは存在しなかった。
//		0以外-->引数のyから座標地点にあったObjectの底辺までの長さ
int ClearZone::ZoneCheck_Y(float x, float y) {
	bool check = false;
	int length_y = 0;
	Object* object = nullptr;
	for (auto i : (*stage_)) {
		if (i != this && 
			i->Left() <= x && x <= i->Right() &&
			i->Top() <= y && y <= i->Base()) {
			check = true;
			object = i;
			break;
		}
	}
	if (check) {
		length_y = (int)(object->Base() - y);
	}
	return length_y;
}
void ClearZone::Clear() {
	
}
ClearZone::ClearZone(float x, float y, float height, float width, int object_number) : Object(x, y, height, width, object_number) {
	quality_ = false;
	switch (object_number_) {
	case 0:
		break;
	default:
		break;
	}
}

void ClearZone::Initialize(IStateChanger *stateChanger, std::vector<Object*>& stage) {
	Object::Initialize(stateChanger, stage);
	for (int i = 0; i != (*stage_).size(); i++) {
		if (typeid(*stage[i]) == typeid(Player)) {
			player_ = stage[i];
		}
	}
}
void ClearZone::Update() {
	if (ClearCheck() && player_->CanClear()) {
		player_->Clear();
	}
}
void ClearZone::Draw() {
	DrawBoxAA(x_, y_, x_ + width_, y_ + height_, GetColor(60, 128, 106), TRUE);//Float型の四点の座標から外枠を描写
}