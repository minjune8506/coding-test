/**
 * @file 15650.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief N과 M (2)
 * @date 2023-02-25
 *
 * 1부터 N까지 자연수 중에서 중복 없이 M개를 고른 수열
 * 고른 수열은 오름차순이어야 한다.
 */
#include <iostream>

int N, M;

int ary[9];
bool visited[9];

void dfs(int cnt) {
	if (cnt == M) {
		for (int i = 0; i < M; i++) {
			std::cout << ary[i] << ' ';
		}
		std::cout << '\n';
	}
	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			if (cnt > 0 && ary[cnt - 1] >= i) {
				continue;
			}
			visited[i] = true;
			ary[cnt] = i;
			dfs(cnt + 1);
			visited[i] = false;
		}
	}
}

int main(void) {
	std::cin >> N >> M;
	dfs(0);
}
