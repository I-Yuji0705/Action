#include "ManualCanvasOptionBase.h"
#include "DxLib.h"

///<summary>
///<para>コンストラクタ</para>
///<para>ManualのStateを変えるポインタの取得</para>
///<param name= "statechanger"><para>ManualのStateを変えるクラスのポインタ</para></param>
///</summary>
ManualCanvasOptionBase::ManualCanvasOptionBase(Keyboard* keyboard, IManualStateChanger* statechanger)  : CanvasOptionBase(keyboard){
	statechanger_ = statechanger;
}