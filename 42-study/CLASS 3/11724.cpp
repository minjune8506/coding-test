/**
 * @file 11724.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 연결 요소의 개수
 * @date 2023-03-10
 *
 * 방향 없는 그래프에서 연결 요소의 개수를 구해라
 * Connected Component
 *
 * 정점의 개수 1 <= N <= 1,000
 * 간선의 개수 0 <= M <= N * (N - 1) / 2
 *
 * DFS를 이용하여 몇번 반복하는지 확인
 */
#include <cstring>
#include <iostream>
#include <vector>

int N, M;

void dfs(std::vector<int> graphs[], bool visited[], int start) {
	visited[start] = true;
	for (int i = 0; i < graphs[start].size(); i++) {
		if (!visited[graphs[start][i]]) {
			dfs(graphs, visited, graphs[start][i]);
		}
	}
}

int main(void) {
	std::cin >> N >> M;

	std::vector<int> graphs[N + 1];
	bool visited[N + 1];

	memset(visited, false, N + 1);

	for (int i = 0; i < M; i++) {
		int start, end;

		std::cin >> start >> end;
		graphs[start].push_back(end);
		graphs[end].push_back(start);
	}

	int count = 0;
	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			count++;
			dfs(graphs, visited, i);
		}
	}
	std::cout << count << '\n';
}
