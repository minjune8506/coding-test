/**
 * @file 1654.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 랜선 자르기
 * @date 2023-01-29
 *
 * N개의 랜선을 만드려고 한다.
 * 길이가 제각각인 K개의 랜선을 가지고 있다.
 * 랜선을 모두 N개의 같은 길이의 랜선으로 만들고 싶어서 K개의 랜선을
 * 잘라서 만들어야 한다.
 * N개보다 많이 만드는것도 N개를 만드는 것에 포함된다.
 * 만들 수 있는 최대 랜선의 길이를 구하는 프로그램
 *
 * - 주어진 랜선의 길이를 입력받는다.
 * - 같은 길이로 N개의 랜선을 만들 수 있는지 검사하는 기능
 * - 최대 길이를 구한다.
 * - 시간초과 -> 이분탐색을 이용하여 풀이
 *
 * 1 <= K <= 10,000
 * 1 <= N <= 1,000,000
 * K <= N
 */
#include <climits>
#include <iostream>
#include <vector>

void solve(std::vector<int> &lanLines, int N, int max) {
	// std::vector<int> answers;
	// std::cout << "max :" << max << std::endl;

	long long start = 1;
	long long end = max;
	long long mid;

	long long answer = 0;
	while (start <= end) {
		long long count = 0;
		mid = (start + end) / 2;
		for (auto lan : lanLines) {
			count += (lan / mid);
		}
		if (count >= N) {
			start = mid + 1;
			if (answer < mid) {
				answer = mid;
			}
		} else {
			end = mid - 1;
		}
	}
	std::cout << answer;
}

int main(void) {
	int K, N;

	std::cin >> K >> N;
	std::vector<int> lanLines;

	int max = INT_MIN;
	for (int i = 0; i < K; i++) {
		int lanLine;

		std::cin >> lanLine;
		if (lanLine > max) {
			max = lanLine;
		}
		lanLines.push_back(lanLine);
	}
	solve(lanLines, N, max);
}
