#include "ItemAction.h"

///<summary>
///<para>コンストラクタ</para>
///<para>操作するitemのポインタを収得する</para>
///<param name="item"><para>item:操作するitemのポインタ</para></param>
///</summary>
ItemAction::ItemAction(Item *item){
	item_ = item;
}