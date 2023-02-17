/**
 * @file 1260.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief DFS와 BFS
 * @date 2023-02-16
 *
 * 그래프를 DFS로 탐색한 결과와 BFS로 탐색한 결과를 출력해라
 * 방분할 수 있는 정점이 여러개인 경우는 번호가 작은 것부터 방문한다.
 * 더 방문할 수 있는 정점이 없는 경우 종료한다.
 * 정점 번호는 1 ~ N번까지
 *
 * 1 <= N <= 1,000
 * 1 <= M <= 10,000
 */
#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

void dfs(std::vector<int> graphs[], bool visited[], int V) {
	std::cout << V << ' ';
	visited[V] = true;
	for (int i = 0; i < graphs[V].size(); i++) {
		if (!visited[graphs[V][i]]) {
			dfs(graphs, visited, graphs[V][i]);
		}
	}
}

void bfs(std::vector<int> graphs[], bool visited[], int V) {
	std::queue<int> q;

	q.push(V);
	visited[V] = true;
	while (!q.empty()) {
		int front = q.front();
		q.pop();
		std::cout << front << ' ';
		for (int i = 0; i < graphs[front].size(); i++) {
			if (!visited[graphs[front][i]]) {
				q.push(graphs[front][i]);
				visited[graphs[front][i]] = true;
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
		int startVertex, endVertex;
		std::cin >> startVertex >> endVertex;
		graphs[startVertex].push_back(endVertex);
		graphs[endVertex].push_back(startVertex);
	}

	for (int i = 1; i < N + 1; i++) {
		std::sort(graphs[i].begin(), graphs[i].end());
	}

	bool visited[N + 1];

	memset(visited, false, sizeof(bool) * (N + 1));
	dfs(graphs, visited, V);
	std::cout << std::endl;

	memset(visited, false, sizeof(bool) * (N + 1));
	bfs(graphs, visited, V);
}
