#include "GameSelectionBase.h"
#include "DxLib.h"

///<summary>
///<para>�R���X�g���N�^</para>
///<para>GameStateChanger�|�C���^�̎���</para>
///</summary>
GameSelectionBase::GameSelectionBase(Keyboard* keyboard,IGameStateChanger* statechanger) :SelectionBase(keyboard) {
	statechanger_ = statechanger;
}