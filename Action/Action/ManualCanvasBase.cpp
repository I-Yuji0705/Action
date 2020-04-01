#include "ManualCanvasBase.h"
#include "DxLib.h"

///<summary>
///<para>コンストラクタ</para>
///<para>ManualのStateを変えるポインタの取得</para>
///<para>引数:</para>
///<param name= "statechanger"><para>ManualのStateを変えるクラスのポインタ</para></param>
///</summary>
ManualCanvasBase::ManualCanvasBase(Keyboard* keyboard,IManualStateChanger* statechanger): CanvasBase(keyboard) {
	statechanger_ = statechanger;
}

///<summary>
///<para>更新処理</para>
///<para>Enterキーか、Escapeキーがあった場合、マニュアル選択画面に移行する</para>
///</summary>
void ManualCanvasBase::Update() {
	if (keyboard_->CheckKey(KEY_INPUT_RETURN) == 1 ||
		keyboard_->CheckKey(KEY_INPUT_ESCAPE) == 1) {
		statechanger_->ChangeState(Manual_Usually);//状態をマニュアル選択画面に移行
	}
}