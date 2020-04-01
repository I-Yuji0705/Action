#include "GameCanvasOptionBase.h"

///<summary>
///<para>コンストラクタ</para>
///<para>GameStateChangerポインタの収得</para>
///</summary>
GameCanvasOptionBase::GameCanvasOptionBase(Keyboard* keyboard, IGameStateChanger* statechanger) : CanvasOptionBase(keyboard) {
	statechanger_ = statechanger;
}