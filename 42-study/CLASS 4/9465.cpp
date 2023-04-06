/**
 * @file 9465.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 스티커
 * @date 2023-04-06
 *
 * 스티커를 2n개 구매.
 * 각 스티커에 점수를 매기고 점수의 합이 최대가 되게 스티커를 뗀다.
 * 스티커 점수의 최댓값을 구하는 프로그램
 */
#include <iostream>
#include <cstring>

void solve() {
	int N;

	std::cin >> N;
	int ary[2][N + 1];

	for (int i = 0; i < 2; i++) {
		for (int j = 1; j <= N; j++) {
			std::cin >> ary[i][j];
		}
	}

	int dp[2][N + 1];
	std::memset(dp, 0, sizeof(int) * 2 * (N + 1));
	
	dp[0][1] = ary[0][1];
	dp[1][1] = ary[1][1];
	int max = std::max(dp[0][1], dp[1][1]);

	for (int i = 2; i <= N; i++) {
		dp[0][i] = ary[0][i] + std::max(dp[1][i - 1], dp[1][i - 2]);
		if (dp[0][i] > max) {
			max = dp[0][i];
		}
		dp[1][i] = ary[1][i] + std::max(dp[0][i - 1], dp[0][i - 2]);
		if (dp[1][i] > max) {
			max = dp[1][i];
		}
	}
	std::cout << max << '\n';
}

int main(void) {
	int T;

	std::cin >> T;
	for (int i = 0; i < T; i++) {
		solve();
	}
}
