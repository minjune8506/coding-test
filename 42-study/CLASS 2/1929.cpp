/**
 * @file 1929.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 소수 구하기
 * @date 2023-01-30
 * 
 * M이상 N이하 소수를 모두 출력하는 프로그램
 * 
 * 1 <= M <= N <= 1,000,000
 * 
 * - 2부터 하나씩 증가하며 나누는 방식은 너무 느림
 * - num / 2 만큼 검사하는 방법 (시간초과)
 * - sqrt(num) 만큼 검사하는 방법 (통과)
 */
#include <iostream>

int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int M, N;

	std::cin >> M >> N;
	for (int i = M; i <= N; i++) {
		if (i < 2) {
			continue;
		}
		bool isPrime = true;
		for (int j = 2; j * j <= i; j++) {
			if (i % j == 0) {
				isPrime = false;
			}
		}
		if (isPrime) {
			std::cout << i;
			if (i != N) {
				std::cout << '\n';
			} else {
				std::cout << std::endl;
			}
		}
	}
}
