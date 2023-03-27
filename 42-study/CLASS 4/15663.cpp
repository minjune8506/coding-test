/**
 * @file 15663.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief N과 M (9)
 * @date 2023-03-27
 *
 * N개의 자연수 중에서 M개를 고른 수열
 * 1 7 9 9
 */
#include <algorithm>
#include <iostream>
#include <vector>

int N, M;
std::vector<int> sequence;
bool visited[9];
int picked[9];

void solve(int cnt) {
	if (cnt == M) {
		for (int i = 0; i < M; i++) {
			std::cout << picked[i] << ' ';
		}
		std::cout << '\n';
		return;
	}
	int tmp = -1;
	for (int i = 0; i < N; i++) {
		if (!visited[i] && tmp != sequence[i]) {
			picked[cnt] = sequence[i];
			tmp = sequence[i];
			visited[i] = true;
			solve(cnt + 1);
			visited[i] = false;
		}
	}
}

int main(void) {
	std::cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int number;
		std::cin >> number;
		sequence.push_back(number);
	}
	std::sort(sequence.begin(), sequence.end());
	solve(0);
}
