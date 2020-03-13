#pragma once

enum ManualState {
	Manual_Usually,
	Manual_Operation,
	Manual_Stage,
	Manual_Rule,
	Manual_Exit,

	Manual_None//無し
};
//Manual内のStateだけを変更するためのインターフェースクラス
class IManualStateChanger {
public:
	virtual ~IManualStateChanger() = 0;
	virtual void ChangeState(ManualState state) = 0;
};