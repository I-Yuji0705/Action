#include "GameCanvasBase.h"
#include "DxLib.h"

///<summary>
///<para>�R���X�g���N�^</para>
///<para>GameStateChanger�|�C���^�̎���</para>
///</summary>
GameCanvasBase::GameCanvasBase(Keyboard* keyboard,IGameStateChanger* statechanger) :CanvasBase(keyboard) {
	statechanger_ = statechanger;
}