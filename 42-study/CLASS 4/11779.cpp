/**
 * @file 11779.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 최소비용 구하기 2
 * @date 2023-05-01
 *
 * n (1 <= n <= 1,000)개의 도시가 있다.
 * m (1 <= m <= 100,000)개의 버스가 있다.
 * A -> B로 가는 버스 비용을 최소화 시키려 한다
 *
 * 최소비용과 경로를 출력해라
 */
#include <climits>
#include <iostream>
#include <queue>
#include <vector>

int N, M, start, end;
std::vector<int> path;

int parents[1001];
int dist[1001];

void dijstra(std::vector<std::pair<int, int> > graphs[]) {
	std::priority_queue<std::pair<int, int> > pq;

	for (int i = 0; i < N + 1; i++) {
		dist[i] = INT_MAX;
	}

	pq.push({0, start});
	dist[start] = 0;

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int curr = pq.top().second;
		pq.pop();

		if (dist[curr] < cost) {
			continue;
		}

		for (int i = 0; i < graphs[curr].size(); i++) {
			int next = graphs[curr][i].first;
			int nextCost = graphs[curr][i].second;

			if (dist[next] > cost + nextCost) {
				dist[next] = cost + nextCost;
				parents[next] = curr;
				pq.push({-dist[next], next});
			}
		}
	}
	std::cout << dist[end] << '\n';

	int temp = end;
	while (temp) {
		path.push_back(temp);
		temp = parents[temp];
	}

	std::cout << path.size() << '\n';
	for (int i = path.size() - 1; i >= 0; i--) {
		std::cout << path[i] << ' ';
	}
	std::cout << '\n';
}

int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N >> M;
	std::vector<std::pair<int, int> > graphs[N + 1];

	for (int i = 0; i < M; i++) {
		int start, end, weight;

		std::cin >> start >> end >> weight;
		graphs[start].push_back({end, weight});
	}

	std::cin >> start >> end;
	dijstra(graphs);
}
