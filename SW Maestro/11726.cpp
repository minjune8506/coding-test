/**
 * @file 11726.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 2xn 타일링
 * @date 2023-02-24
 *
 * 2xn 크기의 직사각형을 1x2, 2x1로 채우는 방법의 수를 구해라
 *
 * 1 <= n <= 1,000
 * 방법의 수를 10,007로 나눈 나머지를 출력
 *
 * 피보나치 수열의 개념으로 DP를 적용하면 풀린다.
 * 경우의 수.. 논리적으로 해보거나 다 해보거나..
 * 나머지 연산을 적용해야 한다. (overflow)
 */
#include <iostream>

int main(void) {
	int N;
	std::cin >> N;
	int dp[N + 1];

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;
	dp[4] = 5;
	for (int i = 5; i < N + 1; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
		if (dp[i] > 10007) {
			dp[i] %= 10007;
		}
	}
	std::cout << dp[N] << std::endl;
}
