#include "ManualStage.h"
#include "DxLib.h"
#include "GraphData.h"
#include "TextData.h"

///<summary>
///<para>コンストラクタ</para>
///<para>マニュアル内のステージ情報の字幕の生成</para>
///</summary>
ManualStage::ManualStage(Keyboard* keyboard, IManualStateChanger* statechanger) :ManualCanvasBase(keyboard,statechanger) {
	drawingData_.push_back((DrawingData*) new TextData(250, 100, "ステージ上のオブジェクト一覧", GetColor(0, 0, 0)));
	drawingData_.push_back((DrawingData*) new GraphData(130, 120, 180, 170, LoadGraph("Image/Player_2.png")));
	drawingData_.push_back((DrawingData*) new TextData(190, 140, "プレイヤー:プレイヤーが操作するキャラクターです。", GetColor(0, 0, 0)));
	drawingData_.push_back((DrawingData*) new GraphData(130, 220, 180, 270, LoadGraph("Image/Item.png")));
	drawingData_.push_back((DrawingData*) new TextData(190, 240, "アイテム：", GetColor(0, 0, 0)));
	drawingData_.push_back((DrawingData*) new TextData(270, 240, "プレイヤーが持ったり、置いたり、", GetColor(0, 0, 0)));
	drawingData_.push_back((DrawingData*) new TextData(270, 260, "投げたりできるオブジェクトです。", GetColor(0, 0, 0)));
	drawingData_.push_back((DrawingData*) new TextData(130, 340, "薄暗いエリア：", GetColor(0, 0, 0)));
	drawingData_.push_back((DrawingData*) new TextData(260, 340, "積み込みエリアです。", GetColor(0, 0, 0)));
	drawingData_.push_back((DrawingData*) new TextData(260, 360, "詳しくは「ステージのクリア条件」にて。", GetColor(0, 0, 0)));
}