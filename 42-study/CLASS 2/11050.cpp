/**
 * @file 11050.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 이항 계수 1
 * @date 2023-02-10
 *
 * 자연수 N과 정수 K가 주어졌을때 이항 계수 (N K)를 구해라
 * 1 <= N <= 10, 0 <= K <= N
 * 
 * 이항 계수?
 * 이항식을 이항정리로 전개했을때 항의 계수
 * 
 * 0 <= K <= n 일때 이항 계수는 n! / k!(n-k)!이다.
 * 
 * - factorial 구현
 * - 계산
 */
#include <iostream>

int factorial(int number) {
	if (number == 0) {
		return 1;
	}
	int factorial = 1;
	for (int i = number; i > 0; i--) {
		factorial *= i;
	}
	return factorial;
}

int main(void) {
	int n, k;

	std::cin >> n >> k;
	std::cout << factorial(n) / (factorial(k) * factorial(n - k)) << std::endl;
}
