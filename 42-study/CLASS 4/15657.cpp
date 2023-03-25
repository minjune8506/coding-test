/**
 * @file 15657.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief N과 M (8)
 * @date 2023-03-25
 *
 * N개의 자연수와 자연수 M이 주어졌을 때, 조건을 만족하는 길이가 M인 수열을 모두
 * 구해라
 * - N개의 자연수 중에서 M개를 고른 수열
 * - 같은 수를 여러번 골라도 된다.
 * - 고른 수열은 비내림차순이어야 한다.
 *   - A1 <= A2 <= ... <= A(k-1) <= Ak
 *
 * 1 <= M <= N <= 8
 */
#include <algorithm>
#include <iostream>

int N, M;
int ary[9];
int numbers[9];

void solve(int cnt, int curr) {
	if (cnt == M) {
		for (int i = 0; i < M; i++) {
			std::cout << ary[i] << ' ';
		}
		std::cout << '\n';
		return;
	}
	for (int i = curr; i < N; i++) {
		ary[cnt] = numbers[i];
		solve(cnt + 1, i);
	}
}

int main(void) {
	std::cin >> N >> M;
	for (int i = 0; i < N; i++) {
		std::cin >> numbers[i];
	}
	std::sort(numbers, numbers + N);
	solve(0, 0);
}
