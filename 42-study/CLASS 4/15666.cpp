/**
 * @file 15666.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief N과 M (12)
 * @date 2023-03-28
 *
 * - N개의 자연수 중에서 M개를 고른 수열
 * - 같은 수를 여러번 골라도 된다.
 * - 고른 수는 비내림차순이어야 한다.
 * - 중복된 수열을 여러번 출력하면 안된다.
 */
#include <algorithm>
#include <iostream>

int N, M;
int numbers[9];
int picked[9];

void solve(int cnt, int curr) {
	if (cnt == M) {
		for (int i = 0; i < M; i++) {
			std::cout << picked[i] << ' ';
		}
		std::cout << '\n';
		return;
	}
	int tmp = -1;
	for (int i = curr; i < N; i++) {
		if (tmp != numbers[i]) {
			picked[cnt] = numbers[i];
			tmp = picked[cnt];
			solve(cnt + 1, i);
		}
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
