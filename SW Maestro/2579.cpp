/**
 * @file 2579.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 계단 오르기
 * @date 2023-02-24
 *
 * 1. 계단은 한 번에 한 계단 또는 두 계단씩 오를 수 있다.
 * 2. 연속된 세 개의 계단을 모두 밟으면 안된다.
 * 3. 마지막 계단은 반드시 밟아야 한다.
 *
 * 총 점수의 최댓값
 */
#include <algorithm>
#include <iostream>
#include <vector>

int main(void) {
	int count;

	std::cin >> count;
	std::vector<int> stairs;
	for (int i = 0; i < count; i++) {
		int score;

		std::cin >> score;
		stairs.push_back(score);
	}

	int dp[count];

	dp[0] = stairs[0];
	dp[1] = stairs[0] + stairs[1];
	dp[2] = std::max(stairs[1] + stairs[2], stairs[0] + stairs[2]);
	for (int i = 3; i < count; i++) {
		dp[i] = std::max(dp[i - 2] + stairs[i],
						 dp[i - 3] + stairs[i - 1] + stairs[i]);
	}

	std::cout << dp[count - 1] << std::endl;
}
