/**
 * @file 9461.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 파도반 수열
 * @date 2023-02-25
 *
 * 1 <= N <= 100
 */
#include <iostream>

int main(void) {
	int testCase;

	std::cin >> testCase;
	long long dp[101];
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;
	dp[4] = 2;
	for (int i = 0; i < testCase; i++) {
		int N;
		std::cin >> N;
		for (int i = 4; i <= N; i++) {
			dp[i] = dp[i - 2] + dp[i - 3];
		}
		std::cout << dp[N] << '\n';
	}
}
