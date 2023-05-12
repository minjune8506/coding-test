/**
 * @file 1238.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 파티
 * @date 2023-05-10
 *
 * N개의 숫자로 구분된 마을
 * N명의 학생이 X (1<= X <= N)번 마을에 모여서 파티를 한다.
 * M개의 단방향 도로가 있고 i번째 길을 지나는데 Ti(1 <= Ti <= 100)
 * 의 시간을 소요한다.
 *
 * 최단시간에 마을을 왔다갔다 하기를 원함
 * 오고가는데 가장 많은 시간을 소비하는 학생은 누군지 구해라
 *
 * 최단시간
 * 다익스트라 알고리즘
 */
#include <climits>
#include <iostream>
#include <queue>
#include <vector>

int N, M, X;

int *dijstra(int start, std::vector<std::pair<int, int> > graphs[]) {
	std::priority_queue<std::pair<int, int> > pq;

	int *dist = new int[N + 1];
	for (int i = 0; i < N + 1; i++) {
		dist[i] = INT_MAX;
	}

	pq.push({0, start});
	dist[start] = 0;
	while (!pq.empty()) {
		std::pair<int, int> top = pq.top();
		int cost = -top.first;
		int curr = top.second;
		pq.pop();

		for (int i = 0; i < graphs[curr].size(); i++) {
			int next = graphs[curr][i].first;
			int nextCost = graphs[curr][i].second;

			if (dist[next] > cost + nextCost) {
				dist[next] = cost + nextCost;
				pq.push({-dist[next], next});
			}
		}
	}
	return dist;
}

int main(void) {
	std::cin >> N >> M >> X;
	std::vector<std::pair<int, int> > graphs[N + 1];

	for (int i = 0; i < M; i++) {
		int start, end, weight;
		std::cin >> start >> end >> weight;

		graphs[start].push_back({end, weight});
	}

	int dist[N + 1];
	for (int i = 1; i <= N; i++) {
		int *temp = dijstra(i, graphs);
		dist[i] = temp[X];
		delete[] temp;
	}

	int *next = dijstra(X, graphs);
	int max = -1;
	for (int i = 1; i <= N; i++) {
		if (dist[i] != INT_MAX && next[i] != INT_MAX) {
			max = std::max(dist[i] + next[i], max);
		}
	}
	std::cout << max << '\n';
}
