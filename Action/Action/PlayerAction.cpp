#include "PlayerAction.h"

///<summary>
///<para>コンストラクタ</para>
///<para>操作するplayerのポインタを収得する</para>
///<param name="player"><para>player:操作するplayerのポインタ</para></param>
///</summary>
PlayerAction::PlayerAction(Player *player){
	player_ = player;
}