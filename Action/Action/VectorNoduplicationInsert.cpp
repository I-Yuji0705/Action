#include "VectorNoduplicationInsert.h"

std::vector<Object*> VectorNoDuplicationInsert(std::vector<Object*> added, std::vector<Object*> add) {
	std::vector<Object*> vector;
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
			if (ok)
				vector.push_back(i);
		}
	}
	return vector;
}