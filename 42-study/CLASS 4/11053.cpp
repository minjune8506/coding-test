/**
 * @file 11053.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 가장 긴 증가하는 부분 수열
 * @date 2023-03-26
 *
 * 수열 A가 주어졌을 때, 가장 긴 증가하는 부분 수열을 구해라
 * A = {10, 20, 10, 30, 20, 50}
 * => 10, 20, 30, 50 (길이 : 4)
 *
 * 1 <= N <= 1,000
 */
#include <algorithm>
#include <iostream>
#include <vector>

int main(void) {
	int N;
	std::cin >> N;
	std::vector<int> sequence;
	std::vector<int> dp;

	for (int i = 0; i < N; i++) {
		int number;
		std::cin >> number;
		sequence.push_back(number);
	}

	dp.push_back(1);
	for (int i = 1; i < N; i++) {
		int max = 1;
		for (int j = i; j >= 0; j--) {
			if (sequence[i] > sequence[j]) {
				max = std::max(dp[j] + 1, max);
			}
		}
		dp.push_back(max);
	}

	std::cout << *(std::max_element(dp.begin(), dp.end())) << '\n';
}
