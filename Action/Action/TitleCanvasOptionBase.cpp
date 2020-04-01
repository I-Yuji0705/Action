#include "TitleCanvasOptionBase.h"

///<summary>
///<para>コンストラクタ</para>
///<para>TitleのStateを変えるポインタの取得</para>
///<param name= "statechanger"><para>TitleのStateを変えるクラスのポインタ</para></param>
///</summary>
TitleCanvasOptionBase::TitleCanvasOptionBase(Keyboard* keyboard, ITitleStateChanger* statechanger) : CanvasOptionBase(keyboard) {
	statechanger_ = statechanger;
}