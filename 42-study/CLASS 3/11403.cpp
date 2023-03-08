/**
 * @file 11403.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 경로 찾기
 * @date 2023-03-08
 *
 * 가중치 없는 방향 그래프 G가 있을 때
 * 모든 정점 (i, j)에 대해 i에서 j로 가는 경로가 있는지 구해라
 *
 * 1 : 존재 / 0 : 존재하지 않음
 * 1 <= N <= 100
 */
#include <cstring>
#include <iostream>
#include <vector>

int graph[101][101];
bool visited[101];
int N;

void dfs(int curr) {
	for (int i = 0; i < N; i++) {
		if (graph[curr][i] && !visited[i]) {
			visited[i] = true;
			dfs(i);
		}
	}
}

int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int edge;
			std::cin >> edge;
			graph[i][j] = edge;
		}
	}

	for (int i = 0; i < N; i++) {
		dfs(i);
		for (int j = 0; j < N; j++) {
			std::cout << visited[j] << ' ';
		}
		std::cout << '\n';
		memset(visited, false, 101);
	}
}
