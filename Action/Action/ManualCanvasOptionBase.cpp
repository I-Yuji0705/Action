#include "ManualCanvasOptionBase.h"
#include "DxLib.h"

///<summary>
///<para>�R���X�g���N�^</para>
///<para>Manual��State��ς���|�C���^�̎擾</para>
///<param name= "statechanger"><para>Manual��State��ς���N���X�̃|�C���^</para></param>
///</summary>
ManualCanvasOptionBase::ManualCanvasOptionBase(Keyboard* keyboard, IManualStateChanger* statechanger)  : CanvasOptionBase(keyboard){
	statechanger_ = statechanger;
}