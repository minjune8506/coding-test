/**
 * @file 10952.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief A + B - 5
 * @date 2023-01-24
 * 
 * A와 B를 입력받고 A + B 출력
 */

#include <iostream>

int main(void) {
	while (true) {
		int A, B;

		std::cin >> A >> B;
		if (!A && !B) {
			break;
		}
		std::cout << A + B << '\n';
	}
}
