/**
 * @file 1389.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 케빈 베이컨의 6단계 법칙
 * @date 2023-02-16
 *
 * 모든 사람들은 최대 6단계 이내에서 서로 아는 사람으로 연결될 수 있다.
 * 케빈 베이컨 게임은 임의의 두 사람이 최소 몇 단계만에 이어질 수 있는지
 * 계산하는 게임이다.
 *
 * BOJ 유저의 수와 친구 관계가 입력으로 주어졌을 때, 케빈 베이컨의 수가
 * 가장 적은 사람을 구하는 프로그램을 작성해라
 *
 * 유저의 수 N (2 <= N <= 100)
 * 친구 관계의 수 M (1 <= M <= 5,000)
 *
 * - 각 유저를 시작점으로 하여 BFS를 한다.
 * - 몇 단계만에 다른 유저에 방문할 수 있는지 계산한다.
 * - 케빈 베이컨 수를 구한다.
 */
#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

int bfs(std::vector<int> friends[], bool visited[], int start, int N) {
	std::queue<int> q;
	int kevin[N + 1];
	memset(kevin, 0, sizeof(int) * (N + 1));

	kevin[start] = 0;
	visited[start] = true;
	q.push(start);
	while (!q.empty()) {
		int front = q.front();
		q.pop();
		for (int i = 0; i < friends[front].size(); i++) {
			if (!visited[friends[front][i]]) {
				q.push(friends[front][i]);
				visited[friends[front][i]] = true;
				kevin[friends[front][i]] = kevin[front] + 1;
			}
		}
	}
	int sum = 0;
	for (int i = 1; i < N + 1; i++) {
		sum += kevin[i];
	}
	return sum;
}

int main(void) {
	int N, M;

	std::cin >> N >> M;
	std::vector<int> friends[N + 1];
	for (int i = 0; i < M; i++) {
		int startVertex, endVertex;
		std::cin >> startVertex >> endVertex;
		friends[startVertex].push_back(endVertex);
		friends[endVertex].push_back(startVertex);
	}

	bool visited[N + 1];
	std::vector<int> sums;
	for (int i = 1; i < N + 1; i++) {
		memset(visited, false, sizeof(bool) * (N + 1));
		int sum = bfs(friends, visited, i, N);
		sums.push_back(sum);
	}
	std::cout << std::min_element(sums.begin(), sums.end()) - sums.begin() + 1 << std::endl;
}
