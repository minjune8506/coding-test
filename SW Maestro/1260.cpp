/**
 * @file 1260.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief DFS와 BFS
 * @date 2023-02-24
 *
 * DFS, BFS로 탐색한 결과
 * 정점 번호가 작은 것을 먼저 방문, 더 이상 방문할 수 없는 경우 종료
 * 정점 번호는 1 ~ N
 *
 * 1 <= N <= 1,000 (정점의 개수)
 * 1 <= M <= 10,000 (간선의 개수)
 * V (탐색 시작 정점)
 */
#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

void dfs(std::vector<int> graphs[], bool visited[], int start) {
	std::cout << start << ' ';
	visited[start] = true;
	for (int i = 0; i < graphs[start].size(); i++) {
		if (!visited[graphs[start][i]]) {
			dfs(graphs, visited, graphs[start][i]);
		}
	}
}

void bfs(std::vector<int> graphs[], bool visited[], int start) {
	std::queue<int> que;
	que.push(start);
	visited[start] = true;
	while (!que.empty()) {
		int front = que.front();
		std::cout << front << ' ';
		que.pop();
		for (int i = 0; i < graphs[front].size(); i++) {
			if (!visited[graphs[front][i]]) {
				visited[graphs[front][i]] = true;
				que.push(graphs[front][i]);
			}
		}
	}
	std::cout << std::endl;
}

int main(void) {
	int N, M, V;

	std::cin >> N >> M >> V;
	std::vector<int> graphs[N + 1];
	for (int i = 0; i < M; i++) {
		int start, end;
		std::cin >> start >> end;

		graphs[start].push_back(end);
		graphs[end].push_back(start);
	}

	for (int i = 0; i < N + 1; i++) {
		std::sort(graphs[i].begin(), graphs[i].end());
	}

	bool visited[N + 1];
	memset(visited, false, sizeof(bool) * (N + 1));
	dfs(graphs, visited, V);
	std::cout << std::endl;

	memset(visited, false, sizeof(bool) * (N + 1));
	bfs(graphs, visited, V);
}
