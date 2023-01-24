/**
 * @file 10950.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief A + B - 3
 * @date 2023-01-24
 * 
 * A와 B를 입력받고 A + B를 출력하는 프로그램
 */

#include <iostream>

int main(void) {
	int testCase;

	std::cin >> testCase;

	for (int i = 0; i < testCase; i++) {
		int A, B;

		std::cin >> A >> B;
		std::cout << A + B << '\n';
	}
	std::cout << std::endl;
}
