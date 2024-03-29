/**
 * @file 1904.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 01타일
 * @date 2023-02-24
 *
 * 각 타일은 0 또는 1이 쓰여 있는 낱장의 타일들이다.
 *
 * 0이 쓰여진 낱장의 타일을 붙여서 00 타일을 만들었다.
 * 현재 1하나만으로 이루어진 타일 / 0타일을 두 개 붙인 00타일만 남았다.
 *
 * 크기가 N인 모든 2진 수열을 만들 수 없게 되었다.
 *
 * e.g.
 * N = 1 (1)
 * N = 2 (00, 11)
 * N = 3 (001, 100)
 * N = 4 (0000, 0011, 1001, 1100, 1111)
 *
 * N이 주어질때 만들 수 있는 모든 가짓수를 세라
 * 1 <= N <= 1,000,000
 *
 * 0.75초.. (DP?)
 * 모든 가짓수를 15746으로 나눈 나머지 출력
 * 피보나치 수열의 형태로 증가하는 DP.. 나머지 연산을 계속 해주니 성공
 */
#include <iostream>

int main(void) {
	int N;

	std::cin >> N;
	int dp[N + 1];

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;
	for (int i = 4; i <= N; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
		if (dp[i] > 15746) {
			dp[i] %= 15746;
		}
	}
	std::cout << dp[N] << std::endl;
}
