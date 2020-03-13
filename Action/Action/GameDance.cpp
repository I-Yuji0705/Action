#include "GameDance.h"

GameDance::GameDance(IGameStateChanger* statechanger) : GameSelectionBase(statechanger) {
}
//ゲームクリア時Playerがダンス中のの初期化処理(何も描写しない)
void GameDance::Initialize() {
}
//ゲームクリア時Playerがダンス中の更新処理（ダンス中は他の状態に移行しない）
void GameDance::Update() {
}