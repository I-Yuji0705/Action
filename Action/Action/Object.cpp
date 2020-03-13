#include "Object.h"
#include "Player.h"
#include "DxLib.h"

Object::Object(float x, float y, float height, float width, int object_number) {
	Set(x, y, height, width);
	this->retry_pos_x_ = x;
	this->retry_pos_y_ = y;
	this->object_number_ = object_number;
}
//終了処理
void Object::Finalize() {
	
	DeleteGraph(graph_handle_);
}
//オブジェクトの左端のｘ座標を返す
float Object::Left() const {
	return x_;
}
//オブジェクトの右端のｘ座標を返す
float Object::Right() const {
	return x_ + width_;
}
//オブジェクトの上辺のｙ座標を返す
float Object::Top() const {
	return y_;
}
//オブジェクトの下辺のｙ座標を返す
float Object::Base() const {
	return y_ + height_;
}
float Object::Center_X() const{
	return x_ + width_ / 2;
}
//対象のオブジェクトと座標先で接触するかを返す
//引数:
//		x:移動先の右端のｘ座標,y:移動先の上端のｙ座標,object:接触しているかを判定するObject
//返り値: true:objectとは接触している,false:objectとは接触していない
bool Object::Check(float x, float y,const Object *object) {
	bool check = false;
	if (object->quality_ &&
		y + height_ > object->Top() && y < object->Base() &&
		x + width_ > object->Left() && x < object->Right())
		check = true;
	return check;
}
//Retry時にオブジェクトの再配置する座標設定
//引数:
//			x:指定先のオブジェクトの右端のx座標
//			y:指定先のオブジェクトの上端のy座標
void Object::RelaySet(float x,float y) {
	this->retry_pos_x_ = x;
	this->retry_pos_y_ = y;
}
//オブジェクトを指定した座標に設定する
//引数:
//			x:指定先のオブジェクトの右端のx座標
//			y:指定先のオブジェクトの上端のy座標
void Object::Set(float x, float y) {
	this->x_ = x;
	this->y_ = y;
}
//オブジェクトを座標に移動する上にオブジェクトの縦幅、横幅を設定する
//引数:
//			x:指定先のオブジェクトの右端のx座標
//			y:指定先のオブジェクトの上端のy座標
//			height:オブジェクトの縦幅
//			width:オブジェクトの縦幅
void Object::Set(float x, float y, float height, float width) {
	Set(x, y);
	this->width_ = width;
	this->height_ = height;
}
//オブジェクトの初期化
//引数:
//			stageChanger:StageManegerのstateを変更するクラスの設定
//			stage:オブジェクトから他のオブジェクトを確認する際に使用
void Object::Initialize(IStateChanger *stateChanger,std::vector<Object*>& stage){
	this->state_changer_ = stateChanger;
	this->stage_ = &stage;
}
//オブジェクトの描写
void Object::Draw() {
	DrawModiGraphF(x_, y_, x_ + width_, y_,x_ + width_, y_ + height_, x_, y_ + height_,graph_handle_, TRUE);//Float型の四点の座標から画像を描写
}
//オブジェクトを移動しようとした際、対象のオブジェクトに接触するか、どうか接触した際にどの部分に接触したかを返す
//引数:
//			point:移動しようとしているオブジェクトの軸 x:x軸,y:y軸
//			num:オブジェクトの軸をどの程度変化させるかを決める
//			object:接触しているかを判定するObject
//返り値:
//				0:接触なし
//				1:対象のobjectに左から接触
//				2:対象のobjectに右から接触
//				3:対象のobjectに上から接触
//				4:対象のobjectに下から接触
int Object::CheckX(float num, const Object *object) {
	int check = 0;
	if (object != this && object->quality_ && Object::Check(x_ + num, y_, object)) {
		if (num > 0) check = 1;//地形の上側から衝突した時
		else check = 2;//地形の下から衝突した時
	}
	return check;
}
int Object::CheckY(float num, const Object *object) {
	int check = 0;
	if (object != this && object->quality_ && Object::Check(x_, y_ + num, object)) {
		if (num > 0) check = 3;//地形の上側から衝突した時
		else check = 4;//地形の下から衝突した時
	}
	return check;
}
//Objectが移動できるかを返す ※デフォルトだと常にfalseを返す
//引数:
//			point:移動しようとしているオブジェクトの軸 x:x軸,y:y軸
//			num:オブジェクトの軸をどの程度変化させるかを決める
bool Object::CanMoveX(float num) {
	return false;
}
bool Object::CanMoveY(float num) {
	return false;
}
//Objectを持ち上げられるかを返す ※デフォルトだと常にfalseを返す
//引数:
//			object:持ち上げようとしている対象
bool Object::CanPicked(const Object *object) {
	return false;
}
//Objectを置くことが出来るかを返す ※デフォルトだと常にfalseを返す
bool Object::CanPutted() {
	return false;
}
//Objectを投げられるかを返す ※デフォルトだと常にfalseを返す
bool Object::CanThrew() {
	return false;
}
//Retryをした際の操作
void Object::Retry() {
	Set(retry_pos_x_, retry_pos_y_);
}
//ObjectによってClear出来るかを返す ※デフォルトだと常にfalseを返す
bool Object::CanClear() {
	return false;
}