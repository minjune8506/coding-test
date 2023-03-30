/**
 * @file 1149.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief RGB거리
 * @date 2023-03-30
 *
 * 집이 N개 있다. (2 <= N <= 1,000)
 * 1번부터 N번집이 순서대로 있다.
 *
 * 집은 빨강, 초록, 파랑 중 하나의 색으로 칠해야 한다.
 * 각각 집을 칠하는 비용이 주어질때, 모든 집을 칠하는 비용의 최솟값
 *
 * - 1번 집의 색은 2번집의 색과 같지 않아야 한다.
 * - N번 집의 색은 N-1번 집의 색과 같지 않아야 한다.
 * - i(2 <= i <= N - 1)번 집의 색은 i - 1번, i + 1번 집의 색과 같지 않아야 한다.
 *
 * DFS -> 메모리 초과 -> 시간초과
 * DP 문제
 */
#include <algorithm>
#include <iostream>
#include <vector>

int N;

int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N;
	std::vector<int> costs[N];
	for (int i = 0; i < N; i++) {
		int r, g, b;
		std::cin >> r >> g >> b;
		costs[i].push_back(r);
		costs[i].push_back(g);
		costs[i].push_back(b);
	}

	int dp[N][3];
	dp[0][0] = costs[0][0];
	dp[0][1] = costs[0][1];
	dp[0][2] = costs[0][2];

	for (int i = 1; i < N; i++) {
		dp[i][0] = std::min(dp[i - 1][1], dp[i - 1][2]) + costs[i][0];
		dp[i][1] = std::min(dp[i - 1][0], dp[i - 1][2]) + costs[i][1];
		dp[i][2] = std::min(dp[i - 1][0], dp[i - 1][1]) + costs[i][2];
	}

	std::cout << *(std::min_element(dp[N - 1], dp[N - 1] + 3)) << std::endl;
}
