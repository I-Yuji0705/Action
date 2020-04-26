#include "TitleToGameOptionData.h"
#include "DxLib.h"

///<summary>
///<para>コンストラクタ</para>
///<para>追加でITitleStateChangerと選択時に変更するTitleStateを受け取る</para>
///<param name= "statechanger"><para>使用するITitleStateCangerのポインタ</para></param>
///<param name= "state"><para>Optionの実行時にChangeStateに渡すstateの値</para></param>
///</summary>
TitleToGameOptionData::TitleToGameOptionData(int x, int y, const char word[128], unsigned int color, ITitleStateChanger* statechanger, TitleState state,const char stagename[30])
	: TitleOptionData(x, y, word, color, statechanger, state) {
	memcpy(stagename_, stagename, 30);
}

///<summary>
///<para>決定処理</para>
///<para>statechanger_のChangeStateをchangestate_の値で実行する</para>
///</summary>
void TitleToGameOptionData::Opt() {
	statechanger_->ChangeState(changestate_,stagename_);
}