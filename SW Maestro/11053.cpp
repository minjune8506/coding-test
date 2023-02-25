/**
 * @file 11053.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 가장 긴 증가하는 부분 수열
 * @date 2023-02-24
 *
 * 수열 A가 주어졌을 때, 가장 긴 증가하는 부분 수열을 구해라
 * 수열 A = {10, 20, 10, 30, 20, 50}인 경우 가장 긴 증가하는 부분 수열은
 * 10, 20, 30, 50 이다.
 *
 * 수열 A의 크기 N (1 <= N <= 1,000)
 * 수열 A를 이루고 있는 Aj (1 <= Aj <= 1,000)
 *
 * 완전 탐색 문제 (시간 초과)
 * DP 이용 반대로 생각하면 풀리는 문제
 */
#include <algorithm>
#include <iostream>
#include <vector>

void solve(std::vector<int> &sequence, int N) {
	int dp[N];
	dp[0] = 1;

	for (int i = 1; i < sequence.size(); i++) {
		int max = 0;
		for (int j = i; j >= 0; j--) {
			if (sequence[j] < sequence[i]) {
				if (max < dp[j]) {
					max = dp[j];
				}
			}
		}
		if (!max) {
			dp[i] = 1;
			continue;
		}
		dp[i] = max + 1;
	}
	std::cout << *(std::max_element(dp, dp + N)) << std::endl;
}

int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N;

	std::cin >> N;
	std::vector<int> sequence;

	for (int i = 0; i < N; i++) {
		int number;
		std::cin >> number;
		sequence.push_back(number);
	}
	solve(sequence, N);
}
