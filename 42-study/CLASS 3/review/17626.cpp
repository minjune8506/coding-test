/**
 * @file 17626.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief Four Squares
 * @date 2023-03-22
 *
 * 모든 자연수는 넷 혹은 그 이하의 제곱수의 합으로 표현 가능하다.
 * 26 = 5^2 + 1^2
 * n을 최소 개수의 제곱수 합으로 표현하는 프로그램
 * 1 <= n <= 50000
 *
 * DP 문제
 * 다시 풀어도 어려움..
 */
#include <climits>
#include <cstring>
#include <iostream>

int main(void) {
	int N;
	std::cin >> N;

	int dp[N + 1];
	dp[0] = 0;
	dp[1] = 1;
	for (int i = 2; i <= N; i++) {
		int min = INT_MAX;
		for (int j = 1; j * j <= i; j++) {
			min = min > dp[i - j * j] ? dp[i - j * j] : min;
		}
		dp[i] = min + 1;
	}
	std::cout << dp[N] << '\n';
}
