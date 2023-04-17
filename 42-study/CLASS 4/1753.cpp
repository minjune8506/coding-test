/**
 * @file 1753.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 최단경로
 * @date 2023-04-17
 *
 * 방향 그래프
 * 주어진 시작점에서 다른 모든 정점으로의 최단 경로를 구하는 프로그램
 * 간선의 가중치는 10 이하의 자연수
 *
 * - 한 정점에서 다른 모든 정점까지의 최단거리
 * - 음의 가중치가 없음
 * -> 다익스트라 알고리즘
 *
 * 1 <= V <= 20,000
 * 1 <= E <= 300,000
 *
 * V는 1번부터 V까지 번호가 매겨져 있다.
 * K (1 <= K <= V)
 * u != v, w <= 10
 *
 * 시작점 자신은 0으로 출력
 * 경로가 존재하지 않는 경우 INF 출력
 *
 * 서로 다른 두 정점 사이에 여러 개의 간선이 존재할 수도 있다.
 */
#include <climits>
#include <iostream>
#include <queue>
#include <vector>

int V, E, start;

void dijstra(std::vector<std::pair<int, int> > graphs[], int start) {
	int dist[V + 1];
	dist[0] = 0;
	for (int i = 1; i < V + 1; i++) {
		dist[i] = INT_MAX;
	}

	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int> >,
						std::greater<std::pair<int, int> > >
		pq;
	pq.push(std::make_pair(0, start));
	dist[start] = 0;

	while (!pq.empty()) {
		int cost = pq.top().first;
		int curr = pq.top().second;
		pq.pop();

		for (int i = 0; i < graphs[curr].size(); i++) {
			int next = graphs[curr][i].first;
			int nextCost = graphs[curr][i].second;

			if (dist[next] > cost + nextCost) {
				dist[next] = cost + nextCost;
				pq.push(std::make_pair(dist[next], next));
			}
		}
	}

	for (int i = 1; i < V + 1; i++) {
		if (dist[i] == INT_MAX) {
			std::cout << "INF" << '\n';
			continue;
		}
		std::cout << dist[i] << '\n';
	}
}

int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> V >> E >> start;
	std::vector<std::pair<int, int> > graphs[V + 1];

	for (int i = 0; i < E; i++) {
		int u, v, w;
		std::cin >> u >> v >> w;
		graphs[u].push_back(std::make_pair(v, w));
	}

	dijstra(graphs, start);
}
