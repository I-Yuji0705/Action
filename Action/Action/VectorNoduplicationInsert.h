#pragma once
#include <vector>
#include "Object.h"

//複数のクラスで使用する関数のまとめ
template <class T>
std::vector<T> VectorNoDuplicationInsert(std::vector<T> added, std::vector<T> add);

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