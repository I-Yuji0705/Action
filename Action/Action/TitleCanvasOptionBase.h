#pragma once
#include "BaseScene.h"
#include "ITitleStateChanger.h"
#include "CanvasOptionBase.h"

//TitleScene���ł̍��ڂ̒��ۃN���X
class TitleCanvasOptionBase : public CanvasOptionBase {
protected:
	ITitleStateChanger* statechanger_;
public:
///<summary>
///<para>�R���X�g���N�^</para>
///<para>Title��State��ς���|�C���^�̎擾</para>
///<para>����:</para>
///<param name= "statechanger"><para>Title��State��ς���N���X�̃|�C���^</para></param>
///</summary>
	TitleCanvasOptionBase(Keyboard* keyboard, ITitleStateChanger* statechanger);
};
