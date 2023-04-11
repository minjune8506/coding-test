/**
 * @file 12865.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 평범한 배낭
 * @date 2023-04-10
 *
 * 여행에 필요하다고 생각하는 N개의 물건이 있다.
 * 각 물건은 무게 W와 가치 V를 가진다.
 * 해당 물건을 배낭에 넣어서 가면 V만큼 즐길 수 있다.
 *
 * 최대 K만큼의 무게만 넣을 수 있는 배낭을들고 다닌다.
 * 물건들의 가치의 최댓값?
 *
 * 1 <= N <= 100
 * 1 <= K <= 100,000
 * 1 <= W <= 100,000
 * 0 <= V <= 1,000
 *
 * Greedy -> 해결 불가능
 * 시간제한 2초
 * 100,000 10만개
 *
 * 완전 탐색? => factorial의 시간복잡도 나올듯 (시간초과)
 */
#include <cstring>
#include <iostream>
#include <vector>

int N, K;
std::vector<std::pair<int, int> > stuffs;

int main(void) {
	std::cin >> N >> K;

	for (int i = 0; i < N; i++) {
		std::pair<int, int> stuff;

		std::cin >> stuff.first >> stuff.second;
		stuffs.push_back(stuff);
	}

	int dp[N + 1][K + 1];
	std::memset(dp, 0, sizeof(int) * (N + 1) * (K + 1));

	for (int i = 0; i < N + 1; i++) {
		for (int j = 0; j < K + 1; j++) {
			if (i == 0 || j == 0) {
				dp[i][j] = 0;
			} else if (stuffs[i - 1].first > j) {
				dp[i][j] = dp[i - 1][j];
			} else if (stuffs[i - 1].first <= j) {
				dp[i][j] =
					std::max(dp[i - 1][j],
							 stuffs[i - 1].second + dp[i - 1][j - stuffs[i - 1].first]);
			}
		}
	}

	std::cout << dp[N][K] << '\n';
}
