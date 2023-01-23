/**
 * @file 2920.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 음계
 * @date 2023-01-23
 * 
 * c d e f g a b C 를 1 ~ 8로 바꾼다.
 * 1부터 8까지 연주하면 ascending
 * 8부터 1까지 연주하면 descending
 * 둘다 아니면 mixed
 * 
 * ascending, descending, mixed를 판단하라.
 */
#include <iostream>
#include <vector>

int isAscending(std::vector<int> &scales) {
	for (int i = 0; i < scales.size() - 1; i++) {
		if (scales[i] > scales[i + 1]) {
			return false;
		}
	}
	return true;
}

int isDescending(std::vector<int> &scales) {
	for (int i = 0; i < scales.size() - 1; i++) {
		if (scales[i] < scales[i + 1]) {
			return false;
		}
	}
	return true;
}

int main(void) {
	std::vector<int> scales;

	for (int i = 0; i < 8; i++) {
		int scale;
		std::cin >> scale;
		scales.push_back(scale);
	}
	if (isAscending(scales)) {
		std::cout << "ascending" << std::endl;
	} else if (isDescending(scales)) {
		std::cout << "descending" << std::endl;
	} else {
		std::cout << "mixed" << std::endl;
	}
}
