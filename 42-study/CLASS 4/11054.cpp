/**
 * @file 11054.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 가장 긴 바이토닉 부분 수열
 * @date 2023-04-27
 *
 * S1 < S2 < ... Sk-1 < Sk > Sk+1 > Sk+2 > ... > SN
 * 부분수열중 가장 긴 바이토닉 수열을 구해라
 *
 * 1 <= N <= 1,000
 * 1 <= Ai <= 1,000
 *
 * 가장 긴 증가하는 수열
 * 앞 뒤로 구한 다음에 최대값 구한뒤 - 1
 */
#include <iostream>
#include <vector>

int N;
std::vector<int> sequence;
void solve() {
	int dp[sequence.size()];
	int reverseDp[sequence.size()];

	for (int i = 0; i < sequence.size(); i++) {
		dp[i] = 1;
		for (int j = i - 1; j >= 0; j--) {
			if (sequence[i] > sequence[j]) {
				dp[i] = std::max(dp[i], dp[j] + 1);
			}
		}
	}

	for (int i = sequence.size() - 1; i >= 0; i--) {
		reverseDp[i] = 1;
		for (int j = i + 1; j < sequence.size(); j++) {
			if (sequence[i] > sequence[j]) {
				reverseDp[i] = std::max(reverseDp[i], reverseDp[j] + 1);
			}
		}
	}

	int max = -1;
	for (int i = 0; i < N; i++) {
		int temp = dp[i] + reverseDp[i];
		max = std::max(temp, max);
	}
	std::cout << max - 1 << '\n';
}

int main(void) {
	std::cin >> N;
	for (int i = 0; i < N; i++) {
		int number;
		std::cin >> number;
		sequence.push_back(number);
	}
	solve();
}
