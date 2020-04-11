#include "CanvasBase.h"
#include "DxLib.h"
#include "ColorCode.h"

///<summary>
///<para>コンストラクタ</para>
///<para>Scene内で使用するキーボードクラスを取得する</para>
///<param name= "keyboard"><para>キーが押されているか確認するクラス</para></param>
///</summary>
CanvasBase::CanvasBase(Keyboard* keyboard) {
	keyboard_ = keyboard;
}

///<summary>
///<para>描写処理</para>
///<para>選択肢と項目の描写処理を行う</para>
///</summary>
void CanvasBase::Draw() { 
	for (auto i : drawingData_) {
		i->Draw();
	}
}



///<summary>
///<para>終了処理</para>
///<para>選択肢と項目の終了処理を行う</para>
///</summary>
void CanvasBase::Finalize() {
	for (auto i : drawingData_) {
		i->Finalize();
	}
}