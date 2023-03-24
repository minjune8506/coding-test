/**
 * @file 15654.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief N과 M (5)
 * @date 2023-03-24
 * N개의 자연수중에서 M개를 고른 수열
 * N개의 수가 주어진다.
 * 1 <= M <= N <= 8
 */
#include <algorithm>
#include <iostream>

int N, M;
int numbers[9];
int picked[9];
bool visited[9];

void solve(int cnt, int curr) {
	if (cnt == M) {
		for (int i = 0; i < M; i++) {
			std::cout << picked[i] << ' ';
		}
		std::cout << '\n';
		return;
	}
	for (int i = 0; i < N; i++) {
		if (!visited[i]) {
			visited[i] = true;
			picked[cnt] = numbers[i];
			solve(cnt + 1, i);
			visited[i] = false;
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
