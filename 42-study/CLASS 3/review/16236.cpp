/**
 * @file 16236.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 아기 상어
 * @date 2023-03-22
 *
 * NxN(2 <= N <= 20) 크기의 공간에 물고기 M마리와 상어 1마리가 있다.
 * 한 칸에는 물고기가 최대 1마리 존재한다.
 * 아기 상어의 처음 크기는 2이다.
 * 1초에 상하좌우 한칸씩 이동 가능하다.
 *
 * 자신의 크기보다 큰 물고기가 있는 칸은 지나갈 수 없다.
 * 자신의 크기보다 작은 물고기만 먹을 수 있다.
 *
 * - 먹을수 있는 물고기가 1마리면 먹는다.
 * - 먹을수 있는 물고기가 여러마리면 거리가 가장 가까운 물고기를 먹는다.
 * 	- 거리가 가까운 물고기가 많다면 가장 위, 여러마리면 가장 왼쪽에 있는
 * 물고기를 먹는다.
 * 몇초동안 물고기를 먹을 수 있는지 구해라
 */
#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

int N;
int map[21][21];
int size = 2;
int count;

typedef struct s_pos {
	int x;
	int y;
	int time;
} t_pos;

t_pos shark;

int dx[4] = {0, -1, 1, 0};
int dy[4] = {-1, 0, 0, 1};

int answer = 0;

bool bfs() {
	std::queue<t_pos> que;
	std::vector<t_pos> fishes;

	bool visited[N][N];
	std::memset(visited, false, N * N);

	visited[shark.y][shark.x] = true;
	que.push(shark);

	while (!que.empty()) {
		t_pos front = que.front();
		que.pop();

		if (map[front.y][front.x] > 0 && map[front.y][front.x] < size) {
			fishes.push_back(front);
			continue;
		}

		for (int i = 0; i < 4; i++) {
			int nx = front.x + dx[i];
			int ny = front.y + dy[i];
			if (nx < 0 || ny < 0 || nx >= N || ny >= N || visited[ny][nx] ||
				size < map[ny][nx]) {
				continue;
			}

			t_pos dest = {nx, ny, front.time + 1};
			visited[ny][nx] = true;
			que.push(dest);
		}
	}

	std::sort(fishes.begin(), fishes.end(),
			  [](t_pos first, t_pos second) -> bool {
				  if (first.time == second.time) {
					  if (first.y == second.y) {
						  return first.x < second.x;
					  }
					  return first.y < second.y;
				  }
				  return first.time < second.time;
			  });
	if (fishes.size()) {
		t_pos fish = fishes[0];
		map[fish.y][fish.x] = 0;
		count++;
		if (count == size) {
			count = 0;
			size++;
		}
		shark.x = fish.x;
		shark.y = fish.y;
		answer += fish.time;
		return true;
	}
	return false;
}

int main(void) {
	std::cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int fish;

			std::cin >> fish;
			if (fish == 9) {
				shark.x = j;
				shark.y = i;
				shark.time = 0;
				fish = 0;
			}
			map[i][j] = fish;
		}
	}

	while (bfs()) {
	}

	std::cout << answer << '\n';
}
