/**
 * @file 2741.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief N 찍기
 * @date 2023-01-23
 * 
 * 1부터 N까지 한 줄에 하나씩 출력하는 프로그램
 * 0 < N < 100,000
 */
#include <iostream>

int main(void) {
	int N;

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N;
	for (int i = 1; i <= N; i++) {
		std::cout << i << '\n';
	}
}
