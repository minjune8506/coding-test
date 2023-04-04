/**
 * @file 11660.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 구간 합 구하기 5
 * @date 2023-04-04
 *
 * N x N 개의 수가 N x N 크기의 표에 채워져 있다.
 * (x1, y1) ~ (x2, y2)까지 합을 구하는 프로그램
 *
 * 1 <= N <= 1024
 * 1 <= M <= 100,000
 */
#include <iostream>

int ary[1025][1025];
int dp[1025][1025];
int N, M;

int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			std::cin >> ary[i][j];
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			dp[i][j] =
				dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1] + ary[i][j];
		}
	}

	for (int i = 0; i < M; i++) {
		int x1, y1, x2, y2;

		std::cin >> x1 >> y1 >> x2 >> y2;
		std::cout << dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1 - 1] +
						 dp[x1 - 1][y1 - 1]
				  << '\n';
	}
}
