/**
 * @file 9095.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 1, 2, 3 더하기
 * @date 2023-03-05
 *
 * 정수 n이 주어졌을 때 n을 1, 2, 3의 합으로 나타내는
 * 방법의 수를 구하는 프로그램
 *
 * 0 < n < 11
 *
 * - 완전탐색 (해결)
 */
#include <iostream>

int count = 0;

void bruteForce(int N, int sum) {
	if (sum > N) {
		return;
	}
	if (sum == N) {
		count++;
	}
	for (int i = 1; i <= 3; i++) {
		bruteForce(N, sum + i);
	}
}

void solve() {
	int N;

	std::cin >> N;
	bruteForce(N, 0);
	std::cout << count << '\n';
	count = 0;
}

int main(void) {
	int t;
	std::cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
}
