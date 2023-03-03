/**
 * @file 7576.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 토마토
 * @date 2023-03-03
 *
 * 하나의 토마토의 인접한 곳은 왼, 오, 앞, 뒤 네 방향에 있는 토마토를
 * 의미한다.
 * 며칠이 지나면 다 익게되는지 최소 일수를 구해라
 *
 * 2 <= M(가로), N(세로) <= 1,000
 */
#include <iostream>
#include <queue>

int storage[1001][1001];
bool visited[1001][1001];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};

typedef struct s_point {
	int x;
	int y;
	int day;
} t_point;

int main(void) {
	int M, N;
	std::queue<t_point> que;

	std::cin >> M >> N;
	bool isPerfect = true;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int tomato;

			std::cin >> tomato;

			if (!tomato) {
				isPerfect = false;
			}
			if (tomato > 0) {
				t_point point = {j, i, 0};
				visited[i][j] = true;
				que.push(point);
			}
			storage[i][j] = tomato;
		}
	}

	int answer = 0;

	while (!que.empty()) {
		t_point temp = que.front();
		answer = temp.day;
		que.pop();

		for (int i = 0; i < 4; i++) {
			int px = temp.x + dx[i];
			int py = temp.y + dy[i];
			int nextDay = temp.day + 1;

			if (px >= M || px < 0 || py >= N || py < 0 || visited[py][px] ||
				storage[py][px]) {
				continue;
			}
			t_point newPoint = {px, py, nextDay};
			visited[py][px] = true;
			storage[py][px] = 1;
			que.push(newPoint);
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!storage[i][j]) {
				std::cout << -1 << '\n';
				return (0);
			}
		}
	}

	std::cout << answer << '\n';
}
