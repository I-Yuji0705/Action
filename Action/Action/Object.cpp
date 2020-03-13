#include "Object.h"
#include "Player.h"
#include <typeinfo.h>
#include "DxLib.h"

Object::Object(float x, float y, float height, float width,Sound* sound) {
	Set(x, y, height, width);
	this->retry_pos_x_ = x;
	this->retry_pos_y_ = y;
	sound_ = sound;
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
//オブジェクトの中心のX座標を返す
float Object::Center_X() const{
	return x_ + width_ / 2;
}
//オブジェクトの横幅を返す
float Object::GetWidth() const {
	return width_;
}
//オブジェクトの縦幅を返す
float Object::GetHeight() const {
	return height_;
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
void Object::Initialize(IGameStateChanger *stateChanger,Collision *collision){
	this->state_changer_ = stateChanger;
}
//オブジェクトの描写
void Object::Draw() {
	DrawBoxAA(x_, y_, x_ + width_, y_ + height_, GetColor(0, 0, 0), TRUE);//Float型の四点の座標から外枠を描写
	const float distance = 5.0f;
	DrawModiGraphF(x_ + distance, y_ + distance, x_ + width_ - distance, y_ + distance,
		x_ + width_ - distance, y_ + height_ - distance, x_, y_ + height_ - distance,graph_handle_, TRUE);//Float型の四点の座標から画像を描写
}
//ObjectX軸に移動できるかを返す ※デフォルトだと常に0を返す
//引数:
//			num:オブジェクトの軸をどの程度移動させるかを決める
float Object::CanPushed(float num) {
	return 0;
}
void Object::Pushed(float num) {
}
////ObjectY軸にが移動できるかを返す ※デフォルトだと常にfalseを返す
////引数:
////			num:オブジェクトの軸をどの程度移動させるかを決める
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