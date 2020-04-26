#include "TitleToGameOptionData.h"
#include "DxLib.h"

///<summary>
///<para>�R���X�g���N�^</para>
///<para>�ǉ���ITitleStateChanger�ƑI�����ɕύX����TitleState���󂯎��</para>
///<param name= "statechanger"><para>�g�p����ITitleStateCanger�̃|�C���^</para></param>
///<param name= "state"><para>Option�̎��s����ChangeState�ɓn��state�̒l</para></param>
///</summary>
TitleToGameOptionData::TitleToGameOptionData(int x, int y, const char word[128], unsigned int color, ITitleStateChanger* statechanger, TitleState state,const char stagename[30])
	: TitleOptionData(x, y, word, color, statechanger, state) {
	memcpy(stagename_, stagename, 30);
}

///<summary>
///<para>���菈��</para>
///<para>statechanger_��ChangeState��changestate_�̒l�Ŏ��s����</para>
///</summary>
void TitleToGameOptionData::Opt() {
	statechanger_->ChangeState(changestate_,stagename_);
}