#pragma once
#include "IGameStateChanger.h"
#include "Collision.h"
#include <vector>
#include "Sound.h"

class Collision;
class Sound;
//ステージ上のオブジェクトの抽象クラス
class Object {
protected:
	Sound* sound_;
	float retry_pos_x_, retry_pos_y_;//初期位置
	int graph_handle_/*,object_number_*/;//オブジェクトの画像、種類ごとの番号
public:
	IGameStateChanger *state_changer_;
	Object(float x, float y, float height, float width,Sound* sound);
	float x_, y_;//オブジェクトの右のx座標、上のy座標
	float width_, height_;//オブジェクトの横幅、縦幅
	int vector_;//向いている方向を示す.1:右を向く,-1:左を向く
	bool quality_;//接触判定があるかどうかを返す
	void Finalize();
	float Left() const;//オブジェクトの左側のX軸
	float Right() const;//オブジェクトの右側のX軸
	float Top() const;//オブジェクトの上部のY軸
	float Base() const;//オブジェクトの下部のY軸
	float Center_X() const;//オブジェクトの中央のx座標
	float GetWidth() const;//オブジェクトの横幅
	float GetHeight() const;//オブジェクトの縦幅
	void Set(float x, float y);//オブジェクトの再設置
	void Set(float x, float y, float height, float width);//オブジェクトの再設置及びサイズの変更
	virtual void Initialize(IGameStateChanger *stateChanger,Collision *collision);//初期化処理
	virtual void Update(){};//更新処理
	virtual void Draw();//描写処理
	virtual float CanPushed(float num);//押されるかどうかを返す
	virtual void Pushed(float num);//押された時の動作
	virtual bool CanMoveY(float num);//移動が可能かどうかを返す
	virtual bool CanPicked(const Object *object);//持ち上げられるかを返す
	virtual void Picked(Object *object) {};//持ち上げられた時の処理
	virtual bool CanPutted();//置けるかどうかを返す
	virtual void Putted() {};//置かれた時の処理
	virtual bool CanThrew();//投げられるかを返す
	virtual void Threw() {};//投げられた時の処理
	virtual void Retry();//リトライをする際の処理
	virtual bool CanClear();
	virtual void Clear() {};//クリア条件を満たしたときの処理
};