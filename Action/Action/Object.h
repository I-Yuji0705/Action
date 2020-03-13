#pragma once
#include "IStateChanger.h"
#include <vector>
//ステージ上のオブジェクトの基底クラス
class Object {
protected:
	//Object **stage_;
	std::vector<Object*> *stage_;
	
	IStateChanger *state_changer_;
	float retry_pos_x_, retry_pos_y_;//初期位置
	int graph_handle_/*,object_number_*/;//オブジェクトの画像、種類ごとの番号 
public:
	//static int object_num_;
	int object_number_;
	float x_, y_;
	float width_, height_;//オブジェクトの右の座標、上の座標、横幅、縦幅
	int vector_;//向いている方向を示す.1:右を向く,-1:左を向く
	bool quality_;//接触判定があるかどうかを返す
	Object(float x, float y, float height, float width, int object_number);//初期化処理
	bool Check(float x, float y,const Object *object);
	void Finalize();
	float Left() const;//オブジェクトの左側のX軸
	float Right() const;//オブジェクトの右側のX軸
	float Top() const;//オブジェクトの上部のY軸
	float Base() const;//オブジェクトの下部のY軸
	float Center_X() const;
	void RelaySet(float x,float y);
	void Set(float x, float y);//オブジェクトの再設置
	void Set(float x, float y, float height, float width);//オブジェクトの再設置及びサイズの変更
	virtual void Initialize(IStateChanger *stateChanger,std::vector<Object*>& stage);
	virtual void Update(){};
	virtual void Draw();
	//virtual int Check(float *point, float num, const Object *object);//point軸にnumを追加した際、他のobjectに当たるか、どの部分に当たったかを返す
	virtual int CheckX(float num, const Object *object);//point軸にnumを追加した際、他のobjectに当たるか、どの部分に当たったかを返す
	virtual int CheckY(float num, const Object *object);//point軸にnumを追加した際、他のobjectに当たるか、どの部分に当たったかを返す
	//virtual bool CanMove(float *point,float num);//移動が可能かどうかを返す
	virtual bool CanMoveX(float num);//移動が可能かどうかを返す
	virtual bool CanMoveY(float num);//移動が可能かどうかを返す
	//virtual void Move(float *point, float num) {};//移動を行う
	virtual void MoveX(float num) {};
	virtual void MoveY(float num) {};
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