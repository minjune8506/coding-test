/**
 * @file 9251.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief LCS
 * @date 2023-04-09
 *
 * Longest Common Subsequence 최장 공통 부분 수열
 * 두 수열이 주어졌을 때
 * 모두의 부분 수열이되는 수열 중 가장 긴 것을 찾는 문제
 *
 * ACAYKP CAPCAK
 * -> ACAK
 */
#include <cstring>
#include <iostream>

int main(void) {
	std::string s1, s2;

	std::cin >> s1 >> s2;

	int dp[s1.length() + 1][s2.length() + 1];
	std::memset(dp, 0, sizeof(int) * (s1.length() + 1) * (s2.length() + 1));

	for (int i = 1; i <= s1.length(); i++) {
		for (int j = 1; j <= s2.length(); j++) {
			if (s1.at(i - 1) != s2.at(j - 1)) {
				dp[i][j] = std::max(dp[i][j - 1], dp[i - 1][j]);
			} else {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
		}
	}

	std::cout << dp[s1.length()][s2.length()] << '\n';
}
