#include "TitleCanvasOptionBase.h"

///<summary>
///<para>�R���X�g���N�^</para>
///<para>Title��State��ς���|�C���^�̎擾</para>
///<param name= "statechanger"><para>Title��State��ς���N���X�̃|�C���^</para></param>
///</summary>
TitleCanvasOptionBase::TitleCanvasOptionBase(Keyboard* keyboard, ITitleStateChanger* statechanger) : CanvasOptionBase(keyboard) {
	statechanger_ = statechanger;
}