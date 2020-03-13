#include "GameSelectionBase.h"
#include "DxLib.h"

///<summary>
///<para>コンストラクタ</para>
///<para>GameStateChangerポインタの収得</para>
///</summary>
GameSelectionBase::GameSelectionBase(Keyboard* keyboard,IGameStateChanger* statechanger) :SelectionBase(keyboard) {
	statechanger_ = statechanger;
}