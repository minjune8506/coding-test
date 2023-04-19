/**
 * @file 1967.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 트리의 지름
 * @date 2023-04-18
 *
 * 시간제한 2초
 *
 * 트리는 사이클이 없는 무방향 그래프이다.
 *
 * 트리에서는 어떤 두 노드를 선택해도 둘 사이에는 경로가 항상 하나만 존재하게
 * 된다. 트리에서 어떤 두 노드를 선택해서 양쪽으로 당길때 가장 길게늘어나는
 * 경우가 있다. 이런 두 노드 사이의 경로의 길이를 트리의 지름이라고 한다.
 *
 * 루트가 있는 트리를 가중치가 있는 간선들로 줄떄
 * 트리의 지름을 구해서 출력하는 프로그램을 작성해라
 *
 * 노드의 개수 n (1 <= n <= 10,000)
 * 부모 노드 / 자식 노드 / 가중치
 *
 * 1. 다익스트라
 *  - 한 노드 -> 다른 모든 노드까지의 거리 (최단거리)
 *  - 모든 노드를 시작점으로 해서 각자 거리를 구해야함
 * 2. 플로이드-워셜
 *  - 모든 노드 <-> 모든 노드 최단 경로를 구하는 알고리즘
 * 3. Topological sort (위상 정렬) x
 *  - DAG 사이클이 없는 방향 그래프에서만 가능
 * 4. 완전 탐색 (DFS, BFS) o
 *  - 한 정점 -> 다른 정점으로의 완전 탐색
 *
 * - 한 정점에서 가장 멀리 있는 정점으로 BFS
 * - 찾은 정점에서 가장 멀리 있는 정점으로 BFS
 * - 트리의 지름..
 */
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

int N;

std::pair<int, int> bfs(std::vector<std::pair<int, int> > graphs[],
						bool visited[], int start) {
	std::queue<std::pair<int, int> > que;

	que.push(std::make_pair(start, 0));
	visited[start] = true;
	std::pair<int, int> max = std::make_pair(start, 0);
	while (!que.empty()) {
		int curr = que.front().first;
		int cost = que.front().second;
		que.pop();
		for (int i = 0; i < graphs[curr].size(); i++) {
			int next = graphs[curr][i].first;
			int weight = graphs[curr][i].second;
			if (!visited[next]) {
				visited[next] = true;
				que.push(std::make_pair(next, weight + cost));
				if (max.second < weight + cost) {
					max.first = next;
					max.second = weight + cost;
				}
			}
		}
	}
	return max;
}

int main(void) {
	std::cin >> N;
	std::vector<std::pair<int, int> > graphs[N + 1];

	for (int i = 0; i < N - 1; i++) {
		int parent, child, weight;
		std::cin >> parent >> child >> weight;
		graphs[parent].push_back(std::make_pair(child, weight));
		graphs[child].push_back(std::make_pair(parent, weight));
	}

	bool visited[N + 1];
	std::memset(visited, false, N + 1);
	std::pair<int, int> temp = bfs(graphs, visited, 1);
	std::memset(visited, false, N + 1);
	std::cout << bfs(graphs, visited, temp.first).second << '\n';

}
