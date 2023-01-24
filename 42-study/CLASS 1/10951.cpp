/**
 * @file 10951.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief A + B - 4
 * @date 2023-01-24
 * 
 * 두 정수 A와 B를 입력받고 A + B를 출력
 */
#include <iostream>

int main(void) {
	while (true) {
		int A, B;

		std::cin >> A >> B;
		if (!std::cin.good()) {
			break;
		}
		std::cout << A + B << '\n';
	}
}
