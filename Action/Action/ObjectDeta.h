#pragma once

//Objectの種類を識別するint型と
//Objectのコンストラクタに必要な情報をまとめた構造体
struct ObjectDeta {
	int object_type_;
	float x_;
	float y_;
	float height_;
	float width_;
};