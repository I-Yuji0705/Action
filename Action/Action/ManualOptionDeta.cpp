#include "ManualOptionDeta.h"

///<summary>
///<para>�R���X�g���N�^</para>
///<para>�ǉ���ITitleStateChanger�ƑI�����ɕύX����TitleState���󂯎��</para>
///<para>����:</para>
///<param name= "statechanger"><para>�g�p����ITitleStateCanger�̃|�C���^</para></param>
///<param name= "state"><para>Option�̎��s����ChangeState�ɓn��state�̒l</para></param>
///</summary>
ManualOptionDeta::ManualOptionDeta(int x, int y, const char word[128], unsigned int color, IManualStateChanger* statechanger, ManualState state)
	: OptionDetaBase(x, y, word, color) {
	statechanger_ = statechanger;
	changestate_ = state;
}

///<summary>
///<para>���菈��</para>
///<para>statechanger_��ChangeState��changestate_�̒l�Ŏ��s����</para>
///</summary>
void ManualOptionDeta::Opt() {
	statechanger_->ChangeState(changestate_);
}