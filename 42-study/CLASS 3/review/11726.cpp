/**
 * @file 11726.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 2xN 타일링
 * @date 2023-03-20
 *
 * 2xN 크기의 직사각형을 1x2, 2x1 타일로 채우는 방법의 수를 구해라
 * 방법의 수를 10,007로 나눈 나머지를 출력한다.
 *
 * 1 <= n <= 1,000
 * 피보나치의 형태로 증가하는건 알겠는데 왜??
 */
#include <iostream>

int main(void) {
	int N;

	std::cin >> N;
	int dp[N + 1];
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i < N + 1; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
		dp[i] %= 10007;
	}
	std::cout << dp[N] << '\n';
}
