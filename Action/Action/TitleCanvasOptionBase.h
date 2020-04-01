#pragma once
#include "BaseScene.h"
#include "ITitleStateChanger.h"
#include "CanvasOptionBase.h"

//TitleScene内での項目の抽象クラス
class TitleCanvasOptionBase : public CanvasOptionBase {
protected:
	ITitleStateChanger* statechanger_;
public:
///<summary>
///<para>コンストラクタ</para>
///<para>TitleのStateを変えるポインタの取得</para>
///<para>引数:</para>
///<param name= "statechanger"><para>TitleのStateを変えるクラスのポインタ</para></param>
///</summary>
	TitleCanvasOptionBase(Keyboard* keyboard, ITitleStateChanger* statechanger);
};
