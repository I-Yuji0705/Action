#include "TitleDelete.h"
#include "DxLib.h"
#include "Keyboard.h"
#include <assert.h>
#include "TextData.h"
#include "TitleOptionData.h"

///<summary>
///<para>コンストラクタ</para>
///<para>ゲームの終了確認する字幕の生成</para>
///</summary>
TitleDelete::TitleDelete(Keyboard* keyboard, ITitleStateChanger* statechanger) :TitleCanvasOptionBase(keyboard,statechanger){
	optionData_.push_back((OptionDataBase*)new TitleOptionData(300, 350, "はい", GetColor(0, 0, 0),statechanger, TitleState::Title_Exit));
	optionData_.push_back((OptionDataBase*)new TitleOptionData(300, 400, "いいえ", GetColor(0, 0, 0),statechanger, TitleState::Title_Usually));
	drawingData_.push_back((DrawingData*)new TextData(200, 300, "本当にゲームを終了しますか？", GetColor(0, 0, 0)));
}