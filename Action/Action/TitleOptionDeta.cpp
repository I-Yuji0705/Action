#include "TitleOptionDeta.h"

///<summary>
///<para>コンストラクタ</para>
///<para>追加でITitleStateChangerと選択時に変更するTitleStateを受け取る</para>
///<para>引数:</para>
///<param name= "statechanger"><para>使用するITitleStateCangerのポインタ</para></param>
///<param name= "state"><para>Optionの実行時にChangeStateに渡すstateの値</para></param>
///</summary>
TitleOptionDeta::TitleOptionDeta(int x, int y, const char word[128], unsigned int color, ITitleStateChanger* statechanger, TitleState state)
	: OptionDetaBase(x, y, word, color) {
	statechanger_ = statechanger;
	changestate_ = state;
}

///<summary>
///<para>決定処理</para>
///<para>statechanger_のChangeStateをchangestate_の値で実行する</para>
///<para>引数:</para>
///<param name= "statechanger"><para>使用するITitleStateCangerのポインタ</para></param>
///<param name= "state"><para>Optionの実行時にChangeStateに渡すstateの値</para></param>
///</summary>
void TitleOptionDeta::Opt() {
	statechanger_->ChangeState(changestate_);
}