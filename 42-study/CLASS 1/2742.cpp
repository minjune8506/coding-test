/**
 * @file 2742.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 기찍 N
 * @date 2023-01-23
 * 
 * N부터 1까지 한 줄에 하나씩 출력하는 프로그램
 */
#include <iostream>

int main(void) {
	int N;

	std::cin >> N;
	for (int i = N; i > 0; i--) {
		std::cout << i << '\n';
	}
}

