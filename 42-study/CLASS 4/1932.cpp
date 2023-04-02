/**
 * @file 1932.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 정수 삼각형
 * @date 2023-04-02
 *
 * 정수 삼각형에서 맨 위부터 하나씩 선택하여 아래쪽으로 내려올때,
 * 선택된 수의 합이 최대가 되는 경로를 구해라
 * 아래층에 있는 수는 현재 층에서 선택된 수의 대각선 왼쪽 또는
 * 대각선 오른쪽에 있는 것중에서만 선택 가능하다.
 *
 * 1. 완전탐색
 * 2. DP
 */
#include <algorithm>
#include <iostream>
#include <vector>

int triangle[501][501];
int dp[501][501];

int main(void) {
	int size;

	std::cin >> size;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < i + 1; j++) {
			std::cin >> triangle[i][j];
		}
	}

	dp[0][0] = triangle[0][0];
	for (int i = 1; i < size; i++) {
		for (int j = 0; j < i + 1; j++) {
			if (!j) {
				dp[i][j] = dp[i - 1][j] + triangle[i][j];
				continue;
			}
			if (j == i) {
				dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
				continue;
			}
			dp[i][j] =
				std::max(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
		}
	}
	std::cout << *(std::max_element(dp[size - 1], dp[size - 1] + size)) << '\n';
}
