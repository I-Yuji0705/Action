#pragma once
//�����̃N���X�Ŏg�p����֐��̂܂Ƃ߂��t�@�C��
#include <vector>
#include "Object.h"


template <class T>
std::vector<T> VectorNoDuplicationInsert(std::vector<T> added, std::vector<T> add);

///<summary>
///<para>��ڂ̈����œn���ꂽ���I�z��ɁA��ڂɓn���ꂽ���I�z����d���Ȃ��ň�ڂ̓��I�z��̌��ɒǉ����A���ʂ�Ԃ�</para>
///<para>��ڂɓn���ꂽ���I�z��̓��A��ڂ̓��I�z��̗v�f�S�ĂƏd�����Ă��Ȃ��v�f��ǉ�����</para>
///<para>����:</para>
///<param name= "added"><para>�ǉ�������ڂ̓��I�z��</para></param>
///<param name= "add"><para>�ǉ������ڂ̓��I�z��</para></param>
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