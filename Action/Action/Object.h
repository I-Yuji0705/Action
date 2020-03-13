#pragma once
#include "Task.h"
#include "IStateChanger.h"
//ステージ上のオブジェクトの基底クラス
class Object :public Task {
protected:
	Object **stage;
	IStateChanger *stateChanger;
	float retryX, retryY;//初期位置
public:
	int vector;//向いている方向を示す.1:右を向く,-1:左を向く
	bool quality;//接触判定があるかどうかを返す
	static int object_num;
	void Finalize() override;
	virtual void Update() override {};
	void Draw() override ;
	float x, y, width, height;//オブジェクトの右の座標、上の座標、横幅、縦幅
	int graphHandle,objNum;//オブジェクトの画像、種類ごとの番号
	virtual void Set(float x, float y, float height, float width, int objNum);//初期化処理
	void Set(float x, float y, float height, float width);
	void Set(float x, float y);
	float Left();
	float Right();
	float Top();
	float Base();
	virtual void Move(float *point, float num);//移動を行う
	virtual bool CanPicked(Object *object);//持ち上げられるかを返す
	virtual void Picked(Object *object);//持ち上げられた時の処理
	virtual void Putted();//置かれた時の処理
	virtual bool CanPutted();//置けるかどうかを返す
	virtual int Check(float *point, float num, Object *object);
	virtual bool CanThrew();//投げられるかを返す
	virtual void Threw();//投げられた時の処理
	virtual void Retry();//リトライをする際の処理
	void RelaySet(float x,float y);
	int Check(float x, float y, Object *object);
	virtual void Initialize(Object **stage);
	virtual void Initialize(IStateChanger *stateChanger, Object **stage);
	virtual void Clear() {};
};