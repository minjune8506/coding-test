/**
 * @file 11727.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 2 x n 타일링 2
 * @date 2023-03-10
 *
 * 2 x n 직사각형을 1x2, 2x1과 2x2 타일로 채우는 방법의 수를 구해라
 *
 * 1 <= n <= 1000
 * 10007로 나눈 나머지 출력
 */
#include <iostream>

int main(void) {
	int N;

	std::cin >> N;
	int dp[N + 1];
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 3;
	for (int i = 3; i <= N; i++) {
		dp[i] = dp[i - 1] + 2 * dp[i - 2];
		if (dp[i] > 10007) {
			dp[i] %= 10007;
		}
	}
	std::cout << dp[N] << '\n';
}
