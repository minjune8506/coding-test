/**
 * @file 1916.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 최소비용 구하기
 * @date 2023-04-06
 *
 * N개의 도시가 있다.
 * 한 도시에서 출발해 다른 도시에 도착하는 M개의 버스가 있다.
 * A번째 도시 -> B번째 도시까지 가는데 드는 버스 비용을 최소화 하려 한다.
 * 최소 비용을 출력해라
 * 도시 번호는 1 ~ N까지이다.
 *
 * A노드 -> B노드로 가는데 어떻게 가야 최소비용으로 갈 수 있나?
 *
 * 도시의 개수 1 <= N <= 1,000
 * 버스의 개수 1 <= M <= 100,000
 */
#include <climits>
#include <iostream>
#include <queue>
#include <vector>

int N, M;

typedef struct s_node {
	int vertex;
	int cost;
} t_node;

void dijkstra(int start, int dist[], std::vector<t_node> graphs[]) {
	dist[start] = 0;
	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int> >,
						std::greater<std::pair<int, int> > >
		pq;

	pq.push(std::make_pair(0, start));

	while (!pq.empty()) {
		int distance = pq.top().first;
		int current = pq.top().second;
		pq.pop();

		if (dist[current] < distance) {
			continue;
		}
		for (int i = 0; i < graphs[current].size(); i++) {
			int next = graphs[current][i].vertex;
			int nextDistance = graphs[current][i].cost + distance;
			if (nextDistance < dist[next]) {
				dist[next] = nextDistance;
				pq.push(std::make_pair(nextDistance, next));
			}
		}
	}
}

int main(void) {
	std::cin >> N >> M;

	std::vector<t_node> graphs[N + 1];

	for (int i = 0; i < M; i++) {
		int start, end, cost;

		std::cin >> start >> end >> cost;
		t_node node = {end, cost};
		graphs[start].push_back(node);
	}

	int start, end;
	std::cin >> start >> end;

	int dist[N + 1];
	for (int i = 1; i <= N; i++) {
		dist[i] = INT_MAX;
	}

	dijkstra(start, dist, graphs);

	std::cout << dist[end] << '\n';
}
