/**
 * @file 1149.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief RGB 거리
 * @date 2023-02-24
 *
 * 집이 N개 있다.
 * 거리는 선분으로 나타낼 수 있고, 1번 집부터 N번 집이 순서대로 있다.
 * 집은 R, G, B중 하나의 색으로 칠해야 한다.
 *
 * 각각의 집을 빨강, 초록, 파랑으로 칠하는 비용이 주어질때
 * 모든 집을 칠하는 비용의 최솟값을 구해보자.
 *
 * 1번집의 색은 2번 집의 색과 같지 않아야 한다.
 * N번 집의 색은 N - 1번 집의 색과 같지 않아야 한다.
 * i(2 <= i <= N - 1)번 집의 색은 i - 1, i + 1번 집의 색과 같지 않아야 한다.
 *
 * 집의수 N (2 <= N <= 1,000)
 *
 * 완전 탐색 문제..? (메모리 초과..) -> 시간 초과.
 * DP 문제..
 */
#include <algorithm>
#include <iostream>
#include <vector>

int main(void) {
	int N;

	std::cin >> N;
	std::vector<int> prices[N + 1];

	for (int i = 1; i <= N; i++) {
		int r, g, b;

		std::cin >> r >> g >> b;
		prices[i].push_back(r);
		prices[i].push_back(g);
		prices[i].push_back(b);
	}

	int dp[N + 1][3];
	dp[1][0] = prices[1][0];
	dp[1][1] = prices[1][1];
	dp[1][2] = prices[1][2];

	for (int i = 2; i <= N; i++) {
		dp[i][0] = std::min(dp[i - 1][1], dp[i - 1][2]) + prices[i][0];
		dp[i][1] = std::min(dp[i - 1][0], dp[i - 1][2]) + prices[i][1];
		dp[i][2] = std::min(dp[i - 1][0], dp[i - 1][1]) + prices[i][2];
	}

	std::cout << *(std::min_element(dp[N], dp[N] + 3)) << std::endl;
}
