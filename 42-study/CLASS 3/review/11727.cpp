/**
 * @file 11727.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 2xn 타일링 2
 * @date 2023-03-20
 *
 * 2xn 직사각형을 1x2, 2x1, 2x2타일로 채우는 방법의수를 구해라
 * 1 <= n <= 1,000
 * 방법의 수를 10,007로 나눈 나머지를 출력한다.
 */
#include <iostream>

int main(void) {
	int N;
	std::cin >> N;
	int dp[N + 1];
	dp[1] = 1;
	dp[2] = 3;
	for (int i = 3; i < N + 1; i++) {
		dp[i] = dp[i - 1] + 2 * dp[i - 2];
		dp[i] %= 10007;
	}
	std::cout << dp[N] << '\n';
}
