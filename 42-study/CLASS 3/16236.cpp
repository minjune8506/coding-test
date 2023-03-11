/**
 * @file 16236.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 아기 상어
 * @date 2023-03-11
 *
 * NxN 크기 공간에 물고기 M마리와 아기 상어 1마리가 있다.
 * 아기 상어와 물고기는 모두 크기를 가지고 있다. (자연수)
 * 가장 처음 아기 상어의 크기 : 2
 * 1초에 움직일 수 있는 칸 : 상 하 좌 우
 *
 * 자신보다 큰 물고기가 있는 칸은 지나갈 수 없다.
 * 자신보다 작은 물고기만 먹을 수 있다.
 * 크기가 같으면 지나갈 순 있지만 먹을 수는 없다.
 *
 * - 더 이상 먹을 수 있는 물고기가 없으면 엄마 상어한테 간다
 * - 먹을 수 있는 물고기가 1마리면 먹으러 간다.
 * - 먹을 수 있는 물고기가 1마리보다 많으면, 가까운 물고기를 먹는다.
 * - 거리가 같으면 가장 위의 물고기 / 가장 왼쪽의 물고기를 먹는다.
 *
 * 상어는 자신의 크기와 같은 수의 물고기를 먹으면 크기가 1 증가한다.
 * 
 * 어찌어찌 풀었는데 어려웠음
 */
#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>

typedef struct t_pos {
	int x;
	int y;
	int time;
} s_pos;

int size = 2;
int count = 0;
int N;
int ocean[21][21];
bool visited[21][21];
t_pos babyShark;
int answer;

int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

bool bfs() {
	std::queue<t_pos> que;

	que.push(babyShark);
	visited[babyShark.y][babyShark.x] = true;

	std::vector<t_pos> positions;

	while (!que.empty()) {
		t_pos front = que.front();
		que.pop();

		if (ocean[front.y][front.x] &&
			ocean[front.y][front.x] < size) {  // 먹음
			positions.push_back(front);
			continue;
		}

		for (int i = 0; i < 4; i++) {
			int nx = front.x + dx[i];
			int ny = front.y + dy[i];
			if (nx < 0 || nx >= N || ny < 0 || ny >= N || visited[ny][nx] ||
				ocean[ny][nx] > size) {
				continue;
			}
			t_pos pos = {nx, ny, front.time + 1};
			que.push(pos);
			visited[pos.y][pos.x] = true;
		}
	}

	std::sort(positions.begin(), positions.end(),
			  [](t_pos first, t_pos second) -> bool {
				  if (first.time == second.time) {
					  if (first.y == second.y) {
						  return first.x < second.x;
					  }
					  return first.y < second.y;
				  }
				  return first.time < second.time;
			  });
	if (positions.size()) {
		int nx = positions[0].x;
		int ny = positions[0].y;
		ocean[ny][nx] = 0;
		babyShark.x = nx;
		babyShark.y = ny;
		answer += positions[0].time;
		count++;
		if (count == size) {
			count = 0;
			size++;
		}
		return true;
	}
	return false;
}

int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int fish;
			std::cin >> fish;
			ocean[i][j] = fish;
			if (fish == 9) {
				babyShark.x = j;
				babyShark.y = i;
				ocean[i][j] = 0;
			}
		}
	}
	while (bfs()) {
		babyShark.time = 0;
		memset(visited, false, 21 * 21);
	}
	std::cout << answer << '\n';
}
