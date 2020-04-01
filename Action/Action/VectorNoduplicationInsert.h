#pragma once
//複数のクラスで使用する関数のまとめたファイル
#include <vector>
#include "Object.h"


template <class T>
std::vector<T> VectorNoDuplicationInsert(std::vector<T> added, std::vector<T> add);

///<summary>
///<para>一つ目の引数で渡された動的配列に、二つ目に渡された動的配列を重複なしで一つ目の動的配列の後ろに追加し、結果を返す</para>
///<para>二つ目に渡された動的配列の内、一つ目の動的配列の要素全てと重複していない要素を追加する</para>
///<para>引数:</para>
///<param name= "added"><para>追加される一つ目の動的配列</para></param>
///<param name= "add"><para>追加する二つ目の動的配列</para></param>
///</summary>
template <class T>
std::vector<T> VectorNoDuplicationInsert(std::vector<T> added, std::vector<T> add) {
	std::vector<T> vector;
	for (auto i : added) {
		vector.push_back(i);
	}
	for (auto i : add) {
		bool ok = true;
		for (auto j : vector) {
			if (j == i) {
				ok = false;
				break;
			}
		}
		if (ok)
			vector.push_back(i);
	}
	return vector;
}