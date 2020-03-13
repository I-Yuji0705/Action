#pragma once
#include "Task.h"
#include "IStateChanger.h"
//ステージ上のオブジェクトの基底クラス
class Object :public Task {
protected:
	Object **stage;
	IStateChanger *stateChanger;
	float retryX, retryY;//初期位置
	int graphHandle,objNum;//オブジェクトの画像、種類ごとの番号 
	bool Check(float x, float y, Object *object);
public:
	static int object_num;
	float x, y,width, height;//オブジェクトの右の座標、上の座標、横幅、縦幅
	int vector;//向いている方向を示す.1:右を向く,-1:左を向く
	bool quality;//接触判定があるかどうかを返す
	void Finalize() override;
	float Left();//オブジェクトの左側のX軸
	float Right();//オブジェクトの右側のX軸
	float Top();//オブジェクトの上部のY軸
	float Base();//オブジェクトの下部のY軸
	void RelaySet(float x,float y);
	void Set(float x, float y);//オブジェクトの再設置
	void Set(float x, float y, float height, float width);//オブジェクトの再設置及びサイズの変更
	virtual void Set(float x, float y, float height, float width, int objNum);//初期化処理
	virtual void Initialize(IStateChanger *stateChanger, Object *stage[]);
	virtual void Update() override {};
	virtual void Draw() override ;
	virtual int Check(float *point, float num, Object *object);//point軸にnumを追加した際、他のobjectに当たるか、どの部分に当たったかを返す
	virtual bool CanMove(float *point,float num);//移動が可能かどうかを返す
	virtual void Move(float *point, float num) {};//移動を行う
	virtual bool CanPicked(Object *object);//持ち上げられるかを返す
	virtual void Picked(Object *object) {};//持ち上げられた時の処理
	virtual bool CanPutted();//置けるかどうかを返す
	virtual void Putted() {};//置かれた時の処理
	virtual bool CanThrew();//投げられるかを返す
	virtual void Threw() {};//投げられた時の処理
	virtual void Retry();//リトライをする際の処理
	virtual void Clear() {};//クリア条件を満たしたときの処理
};