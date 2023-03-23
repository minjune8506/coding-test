/**
 * @file 15650.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief N과 M (2)
 * @date 2023-03-23
 *
 * 자연수 N과 M이 주어졌을때
 * 조건을 만족하는 길이가 M인 수열을 모두 구해라
 *
 * - 1부터 N까지 자연수 중 중복없이 M개를 고른 수열
 * - 고른 수열은 오름차순
 *
 * 1 <= M <= N <= 8
 */
#include <iostream>

bool visited[9];
int ary[9];
int N, M;

void solve(int num, int cnt) {
	if (cnt == M) {
		for (int i = 0; i < M; i++) {
			std::cout << ary[i] << ' ';
		}
		std::cout << '\n';
	}

	for (int i = num; i <= N; i++) {
		if (!visited[i]) {
			visited[i] = true;
			ary[cnt] = i;
			solve(i + 1, cnt + 1);
			visited[i] = false;
		}
	}
}

int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N >> M;
	solve(1, 0);
}
