#pragma once

//GetColorで使用するカラーコードをまとめた構造体
//GetColorで直接渡すと、色の数値を参照することができないため
struct ColorCode {
	int Red;
	int Green;
	int Blue;
};