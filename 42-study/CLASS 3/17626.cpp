/**
 * @file 17626.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief Four Squares
 * @date 2023-03-12
 *
 * 모든 자연수는 넷 혹은 그 이하의 제곱수의 합으로 표현할 수 있다.
 * 자연수 n이 주어질 때, n을 최소 개수의 제곱수 합으로 표현
 *
 * 1 <= n <= 50,000
 *
 * - 완전 탐색 (시간이 너무 오래 걸림)
 * - 시간 복잡도를 줄일 수 있는 다른 방법을 찾아야함
 *
 * DP 문제
 */
#include <iostream>
#include <vector>
#include <climits>

void solve(int N) {
	int dp[N + 1];

	dp[0] = 0;
	dp[1] = 1;
	for (int i = 2; i < N + 1; i++) {
		int min = INT_MAX;
		for (int j = 1; j * j <= i; j++) {
			int tmp = i - j * j;
			min = std::min(min, dp[tmp]);
		}
		dp[i] = min + 1;
	}
	std::cout << dp[N] << '\n';
}

int main(void) {
	int N;
	std::cin >> N;
	solve(N);
}
