/**
 * @file 2438.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 별 찍기 - 1
 * @date 2023-01-19
 * 
 * *
 * **
 * ***
 * ****
 * ... (1 <= N <= 100)
 */
#include <iostream>

int main(void) {
	int N;
	std::cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < i; j++) {
			std::cout << "*";
		}
		std::cout << std::endl;
	}
}
