#include "GameDance.h"

///<summary>
///<para>コンストラクタ</para>
///<para>ダンス時には何も字幕を表示しない</para>
///</summary>
GameDance::GameDance(Keyboard* keyboard,IGameStateChanger* statechanger) : GameSelectionBase(keyboard,statechanger) {
}

///<summary>
///<para>初期化処理</para>
///</summary>
void GameDance::Initialize() {
}

///<summary>
///<para>更新処理</para>
///<para>ダンス時には何も更新せず、字幕側はプレイヤーの操作を受け付けない</para>
///</summary>
void GameDance::Update() {
}