/**
 * @file 15649.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief N과 M (1)
 * @date 2023-02-25
 *
 * 자연수 N, M이 주어질때
 * 아래 조건을 만족하는 길이가 M인 수열을 모두 구해라
 *
 *-  1 ~ N까지 자연수 중에서 중복 없이 M개를 고른 수열
 * 1 2 3 4
 * 1 2 3 4
 * 1 2 3 4
 * 1 2 3 4
 */
#include <iostream>
#include <vector>

int N, M;
int ary[9] = {
	0,
};
bool visited[9] = {
	0,
};

void dfs(int cnt) {
	if (cnt == M) {
		for (int i = 0; i < M; i++) {
			std::cout << ary[i] << ' ';
		}
		std::cout << '\n';
		return;
	}
	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
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
