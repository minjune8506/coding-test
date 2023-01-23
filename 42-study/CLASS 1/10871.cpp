/**
 * @file 10871.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief X보다 작은 수
 * @date 2023-01-23
 * 
 * 정수 N개로 이루어진 수열 A와 정수 X가 주어진다.
 * X보다 작은 수를 모두 출력하라
 */

#include <iostream>

int main(void) {
	int N, X;

	std::cin >> N >> X;
	for (int i = 0; i < N; i++) {
		int number;

		std::cin >> number;
		if (number < X) {
			std::cout << number << ' ';
		}
	}
	std::cout << std::endl;
}
