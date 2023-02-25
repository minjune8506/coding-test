/**
 * @file 15651.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief N과 M(3)
 * @date 2023-02-25
 */
#include <iostream>

int N, M;

int ary[7];

void dfs(int cnt) {
	if (cnt == M) {
		for (int i = 0; i < M; i++) {
			std::cout << ary[i] << ' ';
		}
		std::cout << '\n';
		return;
	}
	for (int i = 1; i <= N; i++) {
		ary[cnt] = i;
		dfs(cnt + 1);
	}
}

int main(void) { std::cin >> N >> M; dfs(0); }
