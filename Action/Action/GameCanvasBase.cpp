#include "GameCanvasBase.h"
#include "DxLib.h"

///<summary>
///<para>コンストラクタ</para>
///<para>GameStateChangerポインタの収得</para>
///</summary>
GameCanvasBase::GameCanvasBase(Keyboard* keyboard,IGameStateChanger* statechanger) :CanvasBase(keyboard) {
	statechanger_ = statechanger;
}