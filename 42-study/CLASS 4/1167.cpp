/**
 * @file 1167.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 트리의 지름
 * @date 2023-05-09
 *
 * 트리의 지름을 구해라
 */
#include <iostream>
#include <queue>
#include <vector>

int V;

std::pair<int, int> bfs(std::vector<std::pair<int, int> > graphs[], int start) {
	std::queue<std::pair<int, int> > que;
	que.push({start, 0});

	bool visited[V + 1];
	for (int i = 0; i < V + 1; i++) {
		visited[i] = false;
	}
	visited[start] = true;

	int maxLength = -1;
	int lastNode = -1;
	while (!que.empty()) {
		std::pair<int, int> front = que.front();
		int node = front.first;
		int time = front.second;
		if (time > maxLength) {
			lastNode = node;
			maxLength = time;
		}
		que.pop();

		for (int i = 0; i < graphs[front.first].size(); i++) {
			int target = graphs[front.first][i].first;
			int weight = graphs[front.first][i].second;
			if (!visited[target]) {
				visited[target] = true;
				que.push({target, time + weight});
			}
		}
	}
	return {lastNode, maxLength};
}

void solve(std::vector<std::pair<int, int> > graphs[]) {
	std::pair<int, int> leaf = bfs(graphs, 1);
	std::pair<int, int> answer = bfs(graphs, leaf.first);
	std::cout << answer.second << '\n';
}

int main(void) {
	std::cin >> V;
	std::vector<std::pair<int, int> > graphs[V + 1];

	for (size_t i = 0; i < V; i++) {
		int start;
		std::cin >> start;

		while (true) {
			int end, weight;
			std::cin >> end;

			if (end < 0) {
				break;
			}
			std::cin >> weight;
			graphs[start].push_back({end, weight});
		}
	}
	solve(graphs);
}
