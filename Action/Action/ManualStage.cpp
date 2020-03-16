#include "ManualStage.h"
#include "DxLib.h"
#include "GraphDeta.h"
#include "SelectionDeta.h"

///<summary>
///<para>コンストラクタ</para>
///<para>マニュアル内のステージ情報の字幕の生成</para>
///</summary>
ManualStage::ManualStage(Keyboard* keyboard, IManualStateChanger* statechanger) :ManualSelectionBase(keyboard,statechanger) {
	drawingdeta_.push_back((DrawingDeta*) new SelectionDeta(250, 100, "ステージ上のオブジェクト一覧", GetColor(0, 0, 0)));
	drawingdeta_.push_back((DrawingDeta*) new GraphDeta(130, 120, 180, 170, LoadGraph("Image/Player_2.png")));
	drawingdeta_.push_back((DrawingDeta*) new SelectionDeta(190, 140, "プレイヤー:プレイヤーが操作するキャラクターです。", GetColor(0, 0, 0)));
	drawingdeta_.push_back((DrawingDeta*) new GraphDeta(130, 220, 180, 270, LoadGraph("Image/Item.png")));
	drawingdeta_.push_back((DrawingDeta*) new SelectionDeta(190, 240, "アイテム：", GetColor(0, 0, 0)));
	drawingdeta_.push_back((DrawingDeta*) new SelectionDeta(270, 240, "プレイヤーが持ったり、置いたり、", GetColor(0, 0, 0)));
	drawingdeta_.push_back((DrawingDeta*) new SelectionDeta(270, 260, "投げたりできるオブジェクトです。", GetColor(0, 0, 0)));
	drawingdeta_.push_back((DrawingDeta*) new SelectionDeta(130, 340, "薄暗いエリア：", GetColor(0, 0, 0)));
	drawingdeta_.push_back((DrawingDeta*) new SelectionDeta(260, 340, "積み込みエリアです。", GetColor(0, 0, 0)));
	drawingdeta_.push_back((DrawingDeta*) new SelectionDeta(260, 360, "詳しくは「ステージのクリア条件」にて。", GetColor(0, 0, 0)));
}

///<summary>
///<para>初期化処理</para>
///</summary>
void ManualStage::Initialize() {
	SelectionBase::Initialize();
}