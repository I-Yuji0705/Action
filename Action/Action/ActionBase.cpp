#include "ActionBase.h"

//接触判定を行うクラスと動作時に音を鳴らすクラスの収得
ActionBase::ActionBase(Collision* collision,Sound* sound) {
	collision_ = collision;
	sound_ = sound;
}