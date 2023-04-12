/**
 * @file 11725.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 트리의 부모 찾기
 * @date 2023-03-26
 *
 * 루트 없는 트리가 주어진다.
 * 트리의 루트를 1이라 했을때, 각 노드의 부모를 구해라
 *
 * 노드의 개수 N (2 <= N <= 100,000)
 */
#include <iostream>
#include <vector>

int N;
bool visited[100001];
int parents[100001];

void dfs(std::vector<int> graphs[], int curr) {
	visited[curr] = true;
	for (int i = 0; i < graphs[curr].size(); i++) {
		if (!visited[graphs[curr][i]]) {
			parents[graphs[curr][i]] = curr;
			dfs(graphs, graphs[curr][i]);
		}
	}
}

int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N;

	std::vector<int> graphs[N + 1];
	for (int i = 1; i < N; i++) {
		int start, end;
		std::cin >> start >> end;

		graphs[start].push_back(end);
		graphs[end].push_back(start);
	}
	dfs(graphs, 1);
	for (int i = 2; i <= N; i++) {
		std::cout << parents[i] << '\n';
	}
}
