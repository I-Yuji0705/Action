#include "GameCanvasOptionBase.h"

///<summary>
///<para>�R���X�g���N�^</para>
///<para>GameStateChanger�|�C���^�̎���</para>
///</summary>
GameCanvasOptionBase::GameCanvasOptionBase(Keyboard* keyboard, IGameStateChanger* statechanger) : CanvasOptionBase(keyboard) {
	statechanger_ = statechanger;
}