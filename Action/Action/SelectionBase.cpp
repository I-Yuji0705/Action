#include "SelectionBase.h"
#include "DxLib.h"
#include "ColorCode.h"

///<summary>
///<para>コンストラクタ</para>
///<para>Scene内で使用するキーボードクラスを取得する</para>
///<para>引数:</para>
///<param name= "keyboard"><para>キーが押されているか確認するクラス</para></param>
///</summary>
SelectionBase::SelectionBase(Keyboard* keyboard) {
	keyboard_ = keyboard;
}


///<summary>
///<para>初期化処理</para>
///<para>選択している項目のを示す変数の初期値を設定する</para>
///</summary>
void SelectionBase::Initialize() {
	selectnum_ = 0;
}

///<summary>
///<para>描写処理</para>
///<para>選択肢と項目の描写処理を行う</para>
///</summary>
void SelectionBase::Draw() { 
	for (auto i : choicedeta_) {
		i->Draw();
	}
	for (auto i : drawingdeta_) {
		i->Draw();
	}
}

///<summary>
///<para>色の更新処理</para>
///<para>選択肢の色を変更する</para>
///<para>選ばれている選択肢の色と選ばれていない選択肢の色を別々に設定し、変更する</para>
///</summary>
void SelectionBase::SelectionColorChange(){
	ColorCode selectcolor = { 0,0,255 };//選ばれている項目の色の設定
	ColorCode nonselectcolor = { 150,150,150 };//選ばれていない項目の色の設定
	//unsigned int selectcolor = GetColor(0,0,255);//選ばれている項目の色の設定
	//unsigned int nonselectcolor = GetColor(150, 150, 150);//選ばれていない項目の色の設定
	int num = 0;
	for (auto i : choicedeta_) {
		if (num == selectnum_) i->ChangeColor(selectcolor);
		else i->ChangeColor(nonselectcolor);
		num++;
	}
}


///<summary>
///<para>選択肢の更新処理</para>
///<para>上下キーを押すことで、選択している選択肢を上下の選択肢に変更する</para>
///<para>一番上の選択肢を選択時に上キーを押すと、一番下の選択肢を選ぶ</para>
///<para>同様に、一番下の選択肢を選択時に下キーを押すと、一番上の選択肢を選ぶ</para>
///</summary>
void SelectionBase::SelectSelection(){
	if (keyboard_->CheckKey(KEY_INPUT_DOWN) == 1) {
		selectnum_ = (selectnum_ + 1) % choicedeta_.size();
	}
	else if (keyboard_->CheckKey(KEY_INPUT_UP) == 1) {
		selectnum_ = (selectnum_ + (int)choicedeta_.size() - 1) % (int)choicedeta_.size();
	}
}

///<summary>
///<para>終了処理</para>
///<para>選択肢と項目の終了処理を行う</para>
///</summary>
void SelectionBase::Finalize() {
	for (auto i : choicedeta_) {
		i->Finalize();
	}
	for (auto i : drawingdeta_) {
		i->Finalize();
	}
}