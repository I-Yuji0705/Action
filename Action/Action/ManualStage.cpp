#include "ManualStage.h"
#include "DxLib.h"
#include "GraphDeta.h"
#include "TextDeta.h"

///<summary>
///<para>コンストラクタ</para>
///<para>マニュアル内のステージ情報の字幕の生成</para>
///</summary>
ManualStage::ManualStage(Keyboard* keyboard, IManualStateChanger* statechanger) :ManualCanvasBase(keyboard,statechanger) {
	drawingdeta_.push_back((DrawingDeta*) new TextDeta(250, 100, "ステージ上のオブジェクト一覧", GetColor(0, 0, 0)));
	drawingdeta_.push_back((DrawingDeta*) new GraphDeta(130, 120, 180, 170, LoadGraph("Image/Player_2.png")));
	drawingdeta_.push_back((DrawingDeta*) new TextDeta(190, 140, "プレイヤー:プレイヤーが操作するキャラクターです。", GetColor(0, 0, 0)));
	drawingdeta_.push_back((DrawingDeta*) new GraphDeta(130, 220, 180, 270, LoadGraph("Image/Item.png")));
	drawingdeta_.push_back((DrawingDeta*) new TextDeta(190, 240, "アイテム：", GetColor(0, 0, 0)));
	drawingdeta_.push_back((DrawingDeta*) new TextDeta(270, 240, "プレイヤーが持ったり、置いたり、", GetColor(0, 0, 0)));
	drawingdeta_.push_back((DrawingDeta*) new TextDeta(270, 260, "投げたりできるオブジェクトです。", GetColor(0, 0, 0)));
	drawingdeta_.push_back((DrawingDeta*) new TextDeta(130, 340, "薄暗いエリア：", GetColor(0, 0, 0)));
	drawingdeta_.push_back((DrawingDeta*) new TextDeta(260, 340, "積み込みエリアです。", GetColor(0, 0, 0)));
	drawingdeta_.push_back((DrawingDeta*) new TextDeta(260, 360, "詳しくは「ステージのクリア条件」にて。", GetColor(0, 0, 0)));
}