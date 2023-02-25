/**
 * @file 15652.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief N과 M (4)
 * @date 2023-02-25
 */
#include <iostream>

int N, M;
int ary[8];

void dfs(int cnt) {
	if (cnt == M) {
		for (int i = 0; i < M; i++) {
			std::cout << ary[i] << ' ';
		}
		std::cout << '\n';
		return;
	}
	for (int i = 1; i <= N; i++) {
		if (cnt > 0 && ary[cnt - 1] > i) {
			continue;
		}
		ary[cnt] = i;
		dfs(cnt + 1);
	}
}

int main(void) {
	std::cin >> N >> M;
	dfs(0);
}
