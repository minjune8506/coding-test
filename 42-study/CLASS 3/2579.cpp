/**
 * @file 2579.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 계단 오르기
 * @date 2023-02-23
 *
 * 각 계단에는 일정한 점수가 있고 밟으면 점수를 얻는다.
 *
 * 1. 계단은 한 번에 한 계단 또는 두 계단을 오를 수 있다.
 * 2. 연속된 연속된 세 개의 계단을 모두 밟아선 안된다. 시작점은 포함되지 않는다.
 * 3. 마지막 도착 계단은 밟아야 한다.
 *
 * 게임에서 얻을 수 있는 점수의 최댓값
 *
 * 계단의 개수는 300이하의 자연수, 점수는 10,000 이하의 자연수
 *
 * - 완전탐색 문제? x
 * - DP로 해결
 */
#include <algorithm>
#include <iostream>
#include <vector>
#include <cstring>

int main(void) {
	std::vector<int> stairs;
	int total;

	std::cin >> total;
	for (int i = 0; i < total; i++) {
		int score;

		std::cin >> score;
		stairs.push_back(score);
	}
	int dp[total];
	memset(dp, 0, sizeof(int) * total);
	dp[0] = stairs[0];									 // 10
	dp[1] = stairs[0] + stairs[1];						 // 30
	dp[2] = std::max(stairs[0], stairs[1]) + stairs[2];	 // 35

	for (int i = 3; i < total; i++) {
		dp[i] = std::max(dp[i - 3] + stairs[i - 1], dp[i - 2]) + stairs[i];
	}
	std::cout << dp[total - 1] << std::endl;
}
