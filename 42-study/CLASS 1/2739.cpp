/**
 * @file 2739.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 구구단
 * @date 2023-01-20
 * 
 * N을 입력받고 구구단 N단을 출력하라
 * 1 <= N <= 9
 */

#include <iostream>

int main(void) {
	int N;
	std::cin >> N;

	for (int i = 1; i <= 9; i++) {
		std::cout << N << " * " << i << " = " << N * i << std::endl;
	}
}
