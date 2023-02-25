/**
 * @file 9095.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 1, 2, 3 더하기
 * @date 2023-02-24
 *
 * 정수 4를 1, 2, 3의 합으로 나타내려면 7가지 방법이 있다.
 * 합을 나타낼때는 수를 1개 이상 사용해야 한다.
 *
 * 1 + 1 + 1 + 1
 * 1 + 1 + 2
 * 1 + 2 + 1
 * 2 + 1 + 1
 * 2 + 2
 * 1 + 3
 * 3 + 1
 *
 * 정수 n이 주어졌을 때 n을 1, 2, 3의 합으로 나타내는 방법의 수는?
 *
 * 0 < n < 11
 *
 * - 완전 탐색 (해결)
 * - DP로 풀었을때 더 효율적
 */
#include <iostream>

int main(void) {
	int testCase;

	std::cin >> testCase;
	int dp[11];
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for (int i = 0; i < testCase; i++) {
		int N;

		std::cin >> N;
		for (int j = 4; j <= N; j++) {
			dp[j] = dp[j - 1] + dp[j - 2] + dp[j - 3];
		}
		std::cout << dp[N] << '\n';
	}
}
