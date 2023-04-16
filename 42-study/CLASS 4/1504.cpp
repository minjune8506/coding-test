/**
 * @file 1504.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 특정한 최단 경로
 * @date 2023-04-16
 *
 * 방향성이 없는 그래프가 주어진다.
 * 1 ~ N번 정점까지 최단 거리로 이동하려고 한다.
 * 두 가지 조건을 만족하면서 최단 경로를 구한다.
 * 임의로 주어진 두 정점은 반드시 통과해야 함
 *
 * 한번 이동했던 정점, 간선도 이동 가능하다.
 *
 * 정점의 개수 N (2 <= N <= 800)
 * 간선의 개수 E (0 <= E <= 200,000)
 * a <- -> b 거리 c
 * 반드시 거쳐야 하는 두 개의 서로 다른 정점 v1, v2
 *
 * 최단 경로가 없을떄 -1 출력
 *
 * 한 정점에서 다른 정점까지의 최단거리 -> 다익스트라 알고리즘
 * 그런데 중간에 거쳐야 하는 정점이 있음
 * start -> v1 -> v2 -> end
 * start -> v2 -> v1 -> end
 * 둘중 하나
 */
#include <climits>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

int N, E;
int v1, v2;

long long *solve(std::vector<std::pair<int, int> > graphs[], int start) {
	std::priority_queue<std::pair<long long, int>,
						std::vector<std::pair<long long, int> >,
						std::greater<std::pair<long long, int> > >
		pq;
	long long *dist = new long long[N + 1];
	for (int i = 0; i < N + 1; i++) {
		dist[i] = LLONG_MAX;
	}

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
	return dist;
}

int main(void) {
	std::cin >> N >> E;

	std::vector<std::pair<int, int> > graphs[N + 1];

	for (int i = 0; i < E; i++) {
		int a, b, c;
		std::cin >> a >> b >> c;
		graphs[a].push_back(std::make_pair(b, c));
		graphs[b].push_back(std::make_pair(a, c));
	}
	std::cin >> v1 >> v2;

	long long *startDist = solve(graphs, 1);
	long long *midDist1 = solve(graphs, v1);
	long long *midDist2 = solve(graphs, v2);

	long long first = startDist[v1] + midDist1[v2] + midDist2[N];
	long long second = startDist[v2] + midDist2[v1] + midDist1[N];
	long long answer = std::min(first, second);
	if (answer >= INT_MAX || answer < 0) {
		std::cout << -1 << '\n';
		return 0;
	}
	std::cout << answer << '\n';
}
