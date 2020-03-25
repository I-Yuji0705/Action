#include "TitleDelete.h"
#include "DxLib.h"
#include "Keyboard.h"
#include <assert.h>
#include "TextDeta.h"
#include "TitleOptionDeta.h"

///<summary>
///<para>コンストラクタ</para>
///<para>ゲームの終了確認する字幕の生成</para>
///</summary>
TitleDelete::TitleDelete(Keyboard* keyboard, ITitleStateChanger* statechanger) :TitleCanvasOptionBase(keyboard,statechanger){
	optiondeta_.push_back((OptionDetaBase*)new TitleOptionDeta(300, 350, "はい", GetColor(0, 0, 0),statechanger, Title_Exit));
	optiondeta_.push_back((OptionDetaBase*)new TitleOptionDeta(300, 400, "いいえ", GetColor(0, 0, 0),statechanger, Title_Usually));
	drawingdeta_.push_back((DrawingDeta*)new TextDeta(200, 300, "本当にゲームを終了しますか？", GetColor(0, 0, 0)));
}