/**
 * @file 1932.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 정수 삼각형
 * @date 2023-02-24
 *
 * 맨 위층 7부터 시작해서 아래에 있는 수 중 하나를 선택하여
 * 아래층으로 내려올 때,
 * 선택된 수의 합이 최대가 되는 경로를 구하는 프로그램
 * 아래층에 있는 수는 현재 층에서 선택된 수의 대각선으로만 선택할 수 있다.
 *
 * 1 <= 삼각형의 크기 <= 500
 * 각 수는 정수 범위는 0 <= 수 <= 9999
 * 10000 * 500 => 5,000,000 (int)
 *
 * DP로 해결
 */
#include <algorithm>
#include <iostream>
#include <vector>

int main(void) {
	int N;
	std::cin >> N;

	std::vector<int> triangle[N];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i + 1; j++) {
			int score;

			std::cin >> score;
			triangle[i].push_back(score);
		}
	}

	int dp[N][N];
	dp[0][0] = triangle[0][0];
	for (int i = 1; i < N; i++) {
		dp[i][0] = dp[i - 1][0] + triangle[i][0];
		for (int j = 1; j < i; j++) {
			dp[i][j] =
				std::max(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
		}
		dp[i][i] = dp[i - 1][i - 1] + triangle[i][i];
	}

	std::cout << *(std::max_element(dp[N - 1], dp[N - 1] + N)) << std::endl;
}
