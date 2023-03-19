/**
 * @file 2579.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 계단 오르기
 * @date 2023-03-19
 *
 * 1. 계단은 한번에 하나 / 두계단씩 오를 수 있다.
 * 2. 연속된 3개의 계단을 모두 밟으면 안된다.
 * 3. 마지막 계단은 반드시 밟아야 한다.
 *
 * 게임에서 얻을 수 있는 총 점수의 최댓값
 */
#include <iostream>
#include <vector>

int main(void) {
	int N;

	std::cin >> N;
	std::vector<int> stairs;

	for (int i = 0; i < N; i++) {
		int stair;

		std::cin >> stair;
		stairs.push_back(stair);
	}

	int dp[N];
	dp[0] = stairs[0];
	if (N > 1) {
		dp[1] = stairs[0] + stairs[1];
	}
	if (N > 2) {
		dp[2] = std::max(stairs[0], stairs[1]) + stairs[2];
	}

	for (int i = 3; i < N; i++) {
		dp[i] = std::max(dp[i - 3] + stairs[i - 1], dp[i - 2]) + stairs[i];
	}

	std::cout << dp[N - 1] << '\n';
}
