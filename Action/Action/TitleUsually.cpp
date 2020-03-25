#include "TitleUsually.h"
#include "DxLib.h"
#include "Keyboard.h"
#include <assert.h>
#include "TextDeta.h"
#include "TitleOptionDeta.h"

///<summary>
///<para>コンストラクタ</para>
///<para>字幕の生成</para>
///</summary>
TitleUsually::TitleUsually(Keyboard* keyboard, ITitleStateChanger* statechanger) :TitleCanvasOptionBase(keyboard,statechanger){
	optiondeta_.push_back((OptionDetaBase*) new TitleOptionDeta(400, 300, "ゲームスタート", GetColor(0, 0, 0),statechanger, Title_Game));
	optiondeta_.push_back((OptionDetaBase*) new TitleOptionDeta(400, 350, "ゲーム終了", GetColor(0, 0, 0),statechanger, Title_Delete));
	optiondeta_.push_back((OptionDetaBase*) new TitleOptionDeta(400, 400, "操作説明", GetColor(0, 0, 0), statechanger, Title_Intersection));
	drawingdeta_.push_back((DrawingDeta*) new TextDeta(130, 380, "Enterキー:項目の決定", GetColor(0, 0, 0)));
	drawingdeta_.push_back((DrawingDeta*) new TextDeta(130, 400, "上下キー：項目の選択", GetColor(0, 0, 0)));
}
