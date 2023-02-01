/**
 * @file 2231.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 분해합
 * @date 2023-02-01
 * 
 * 자연수 N이 있을 때, N의 분해합은 N과 N을 이루는 각 자리수의 합을 의미한다.
 * 자연수 M의 분해합이 N인 경우
 * M을 N의 생성자라고 한다.
 * 
 * 245의 분해합은 245 + 2 + 4 + 5 = 256 이다.
 * 따라서 245는 256의 생성자이다.
 * 
 * 자연수 N이 주어졌을 때, N의 가장 작은 생성자를 구하는 프로그램
 * 생성자가 없는경우 0을 출력한다.
 * 
 */
#include <iostream>

int getSum(int number) {
	int origin = number;
	int sum = 0;
	while (number != 0) {
		sum += (number % 10);
		number /= 10;
	}
	return origin + sum;
}

int main(void) {
	int N;

	std::cin >> N;

	for (int i = 1; i <= N; i++) {
		if (getSum(i) == N) {
			std::cout << i << std::endl;
			return (0);
		}
	}
	std::cout << 0 << std::endl;
}
