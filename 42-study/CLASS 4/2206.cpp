/**
 * @file 2206.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 벽 부수고 이동하기
 * @date 2023-05-02
 *
 * NxM의 행렬로 표현되는 맵
 * 0은 이동할 수 있는 곳
 * 1은 이동할 수 없는 곳
 * (1, 1) => (N, M) 이동
 * 최단 경로
 * 시작하는 칸과 끝나는 칸도 포함
 * 벽을 한개까지 부수고 이동할 수 있다.
 *
 * 1 <= N <= 1,000
 * 1 <= M <= 1,000
 *
 * 최단거리
 * - BFS를 이용하여 탐색해야함
 * - 한개까지 벽을 부술 수 있음
 * - 어떤 벽을 부술건지 ?
 *
 * 1) 완전탐색으로 하나씩 벽을 부숴본다.
 * 2) BFS를 수행하는 도중 더이상 이동할 수 없으면 부순다.
 *  2-1) 부쉈는지 확인하는 변수하나를 둬서 각 경로마다 1번씩 부술 수 있게 함
 * 0100
 * 0010
 * 1101
 * 1100
 *
 * 0000
 * 0110
 * 0110
 * 0100
 */
#include <iostream>
#include <queue>

#define MAX 1001

int N, M;
int map[MAX][MAX];
bool visited[MAX][MAX][2];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

typedef struct s_path {
	int x;
	int y;
	int cnt;
	bool crash;
} t_path;

int solve() {
	std::queue<t_path> que;
	que.push({0, 0, 1, false});
	visited[0][0][0] = true;

	while (!que.empty()) {
		t_path front = que.front();
		que.pop();

		if (front.y == N - 1 && front.x == M - 1) {
			return front.cnt;
		}
		for (int i = 0; i < 4; i++) {
			int nx = front.x + dx[i];
			int ny = front.y + dy[i];

			if (visited[ny][nx][front.crash] || nx < 0 || nx >= M || ny < 0 ||
				ny >= N) {
				continue;
			}

			if (map[ny][nx] && front.crash) {
				continue;
			}

			if (map[ny][nx] && !front.crash) {
				que.push({nx, ny, front.cnt + 1, true});
				visited[ny][nx][front.crash] = true;
				continue;
			}

			visited[ny][nx][front.crash] = true;
			que.push({nx, ny, front.cnt + 1, front.crash});
		}
	}
	return -1;
}

int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N >> M;
	for (int i = 0; i < N; i++) {
		std::string line;

		std::cin >> line;
		for (int j = 0; j < line.length(); j++) {
			map[i][j] = (int)(line[j] - '0');
		}
	}
	std::cout << solve() << '\n';
}
