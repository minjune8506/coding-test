/**
 * @file 4153.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 직각삼각형
 * @date 2023-01-27
 * 
 * 세 변의 길이가 주어질 때 직각삼각형인지 아닌지 구분해라
 * 
 * 마지막 줄에는 0 0 0 이 입력된다.
 */
#include <iostream>
#include <algorithm>
#include <cmath>

bool isRightAngledTriangle(int x, int y, int z) {
	if (std::pow(x, 2) == std::pow(y, 2) + std::pow(z, 2)) {
		return true;
	}
	return false;
}

int main(void) {
	while (true) {
		int x, y, z;

		std::cin >> x >> y >> z;
		if (!x && !y && !z) {
			return (0);
		}
		if (isRightAngledTriangle(x, y, z) ||
			isRightAngledTriangle(y, x, z) ||
			isRightAngledTriangle(z, x, y)) {
				std::cout << "right" << std::endl;
				continue;
		}
		std::cout << "wrong" << std::endl;
	}
}
