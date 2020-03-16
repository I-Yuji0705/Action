#include "Object.h"
#include "Player.h"
#include <typeinfo.h>
#include "DxLib.h"

//Danceをpublicにして、
//ダンス時に呼び出すようにすればCanClearはいらないし、
//ClearAreaにSoundを渡す必要もない？
//もしくは、クリアしているかを
//boolで判断するべき？

///<summary>
///<para>コンストラクタ</para>
///<para>オブジェクトの左上のX座標とY座標、横幅と縦幅を設定する</para>
///<para>また、初期位置を保存する</para>
///<para>引数:</para>
///<param name="x"><para>x:Objectの左上のX座標</para></param>
///<param name="y"><para>y:Objectの左上のY座標</para></param>
///<param name="height"><para>height:Objectの左から右までの横幅</para></param>
///<param name="width"><para>width:Objectの上から下までの縦幅</para></param>
///</summary>
Object::Object(float x, float y, float height, float width) {
	Set(x, y, height, width);
	this->retry_pos_x_ = x;
	this->retry_pos_y_ = y;
}

///<summary>
///<para>終了処理</para>
///<para>メモリ上の画像を削除する</para>
///</summary>
void Object::Finalize() {
	DeleteGraph(graph_handle_);
}

///<summary>
///<para>オブジェクトの左端のｘ座標を返す</para>
///<para>戻り値:</para>
///<returns>
///<para>オブジェクトの左端のｘ座標</para>
///</returns>
///</summary>
float Object::Left() const {
	return x_;
}

///<summary>
///<para>オブジェクトの右端のｘ座標を返す</para>
///<para>戻り値:</para>
///<returns>
///<para>オブジェクトの右端のｘ座標</para>
///</returns>
///</summary>
float Object::Right() const {
	return x_ + width_;
}

///<summary>
///<para>オブジェクトの上辺のｙ座標を返す</para>
///<para>戻り値:</para>
///<returns>
///<para>オブジェクトの上辺のｙ座標</para>
///</returns>
///</summary>
float Object::Top() const {
	return y_;
}

///<summary>
///<para>オブジェクトの下辺のｙ座標を返す</para>
///<para>戻り値:</para>
///<returns>
///<para>オブジェクトの下辺のｙ座標</para>
///</returns>
///</summary>
float Object::Base() const {
	return y_ + height_;
}

///<summary>
///<para>オブジェクトの中心のX座標を返す</para>
///<para>戻り値:</para>
///<returns>
///<para>オブジェクトの中心のX座標</para>
///</returns>
///</summary>
float Object::Center_X() const{
	return x_ + width_ / 2;
}

///<summary>
///<para>オブジェクトの横幅を返す</para>
///<para>戻り値:</para>
///<returns>
///<para>オブジェクトの横幅</para>
///</returns>
///</summary>
float Object::GetWidth() const {
	return width_;
}

///<summary>
///<para>オブジェクトの縦幅を返す</para>
///<para>戻り値:</para>
///<returns>
///<para>オブジェクトの縦幅</para>
///</returns>
///</summary>
float Object::GetHeight() const {
	return height_;
}

///<summary>
///<para>オブジェクトを指定した座標に設定する</para>
///<para>引数:</para>
///<param name="x"><para>x:設定するObjectの左上のX座標</para></param>
///<param name="y"><para>y:設定するObjectの左上のY座標</para></param>
///</summary>
void Object::Set(float x, float y) {
	this->x_ = x;
	this->y_ = y;
}

///<summary>
///<para>オブジェクトを指定した座標に設定する</para>
///<para>追加でオブジェクトの縦幅、横幅を設定する</para>
///<para>引数:</para>
///<param name="x"><para>x:設定するObjectの左上のX座標</para></param>
///<param name="y"><para>y:設定するObjectの左上のY座標</para></param>
///<param name="height"><para>height:Objectの左から右までの横幅</para></param>
///<param name="width"><para>width:Objectの上から下までの縦幅</para></param>
///</summary>
void Object::Set(float x, float y, float height, float width) {
	Set(x, y);
	this->width_ = width;
	this->height_ = height;
}

//オブジェクトの描写
//void Object::Draw() {
//	DrawBoxAA(x_, y_, x_ + width_, y_ + height_, GetColor(0, 0, 0), TRUE);//Float型の四点の座標から外枠を描写
//	const float distance = 5.0f;
//	DrawModiGraphF(x_ + distance, y_ + distance, x_ + width_ - distance, y_ + distance,
//		x_ + width_ - distance, y_ + height_ - distance, x_, y_ + height_ - distance,graph_handle_, TRUE);//Float型の四点の座標から画像を描写
//}

///<summary>
///<para>押されようとしている数字から、自分が押されることのできる数字を返す</para>
///<para>デフォルトだと常に0を返す</para>
///<para>引数:</para>
///<param name="num"><para>num:現在の位置から動かそうとしている座標への差</para></param>
///<para>戻り値:</para>
///<returns>
///<para>numに対して、実際にこのObjectを動かせる距離</para>
///</returns>
///</summary>
float Object::CanPushed(float num) {
	return 0;
}

///<summary>
///<para>Objectに持たれるかを返す</para>
///<para>デフォルトだと常にfalseを返す</para>
///<para>引数:</para>
///<param name="object"><para>object:自分を持つObject</para></param>
///<para>戻り値:</para>
///<returns>
///<para>true:自分を持つことができる</para>
///<para>false:自分を持つことができない</para>
///</returns>
///</summary>
bool Object::CanPicked(const Object *object) {
	return false;
}

///<summary>
///<para>今Objectが置かれることができるかを返す</para>
///<para>デフォルトだと常にfalseを返す</para>
///<para>戻り値:</para>
///<returns>
///<para>true:自分を持つことができる</para>
///<para>false:自分を持つことができない</para>
///</returns>
///</summary>
bool Object::CanPutted() {
	return false;
}

///<summary>
///<para>今Objectが投げられることができるかを返す</para>
///<para>デフォルトだと常にfalseを返す</para>
///<para>戻り値:</para>
///<returns>
///<para>true:自分投げることができる</para>
///<para>false:自分を投げることができない</para>
///</returns>
///</summary>
bool Object::CanThrew() {
	return false;
}

///<summary>
///<para>リトライ処理</para>
///<para>初期位置に座標を設定する</para>
///</summary>
void Object::Retry() {
	Set(retry_pos_x_, retry_pos_y_);
}

///<summary>
///<para>今クリアできるかを返す</para>
///<para>デフォルトだと常にfalseを返す</para>
///<returns>
///<para>true:自分投げることができる</para>
///<para>false:自分を投げることができない</para>
///</returns>
///</summary>
bool Object::CanClear() {
	return false;
}
