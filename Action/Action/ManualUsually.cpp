#include "ManualUsually.h"
#include "DxLib.h"
#include <assert.h>
#include "TextDeta.h"
#include "ManualOptionDeta.h"

///<summary>
///<para>コンストラクタ</para>
///<para>マニュアル内で他のマニュアルを選択する字幕の生成</para>
///</summary>
ManualUsually::ManualUsually(Keyboard* keyboard, IManualStateChanger* statechanger) :ManualCanvasOptionBase(keyboard,statechanger) {
	drawingdeta_.push_back((DrawingDeta*)new TextDeta(250, 100, "マニュアル", GetColor(0, 0, 0)));
	optiondeta_.push_back((OptionDetaBase*)new ManualOptionDeta(130, 250, "プレイヤーの操作方法", GetColor(0, 0, 0),statechanger, Manual_Operation));
	optiondeta_.push_back((OptionDetaBase*)new ManualOptionDeta(130, 300, "ステージ上のオブジェクト一覧", GetColor(0, 0, 0), statechanger, Manual_Stage));
	optiondeta_.push_back((OptionDetaBase*)new ManualOptionDeta(130, 350, "ステージのクリア条件", GetColor(0, 0, 0), statechanger, Manual_Rule));
	optiondeta_.push_back((OptionDetaBase*)new ManualOptionDeta(130, 400, "メニューに戻る", GetColor(0, 0, 0), statechanger, Manual_Exit));
}