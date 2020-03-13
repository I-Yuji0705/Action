#include "GameDance.h"

GameDance::GameDance(Keyboard* keyboard,IGameStateChanger* statechanger) : GameSelectionBase(keyboard,statechanger) {
}
//ゲームクリア時Playerがダンス中のの初期化処理(何も描写しない)
void GameDance::Initialize() {
}
//ゲームクリア時Playerがダンス中の更新処理（ダンス中は他の状態に移行しない）
void GameDance::Update() {
}