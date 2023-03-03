/**
 * @file 7569.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 토마토
 * @date 2023-03-02
 *
 * 토마토를 3차원으로 쌓아서 저장한다.
 *
 * 보관 후 하루가 지나면, 익은 토마토들의 인접한 곳에 있는
 * 익지 않은 토마토들은 익은 토마토의 영향을 받아 익게 된다.
 *
 * 인접 : 위, 아래, 왼, 오, 앞, 뒤
 * 창고에 보관된 토마토들이 며칠이 지나면 다 익게 되는지 알고 싶다.
 * 최소 일수를 구해라. 토마토가 없는 칸도 있다.
 *
 * 2 <= M(가로 칸) <= 100
 * 2 <= N(세로 칸) <= 100
 * 1 <= H(높이) <= 100
 * 1 : 익은 토마토
 * 0 : 익지 않은 토마토
 * -1 : 토마토가 없는 칸
 *
 * bfs를 응용해서 풀어야 함
 * 전체 queue를 중심으로 bfs 수행
 */
#include <iostream>
#include <queue>
#include <vector>

int M, N, H;
int storage[101][101][101];
bool visited[101][101][101];

int dm[] = {0, 0, 1, -1, 0, 0};
int dn[] = {0, 0, 0, 0, 1, -1};
int dh[] = {1, -1, 0, 0, 0, 0};

typedef struct s_point {
	int m;
	int n;
	int h;
	int count;
} t_point;

std::queue<t_point> que;
int day;

int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> M >> N >> H;
	bool isFinish = true;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				int tomato;

				std::cin >> tomato;
				if (!tomato) {
					isFinish = false;
				}
				if (tomato == 1) {
					t_point temp = {k, j, i, 0};
					visited[i][j][k] = true;
					que.push(temp);
				}
				storage[i][j][k] = tomato;
			}
		}
	}

	if (isFinish) {
		std::cout << 0 << '\n';
		return (0);
	}

	while (!que.empty()) {
		t_point temp = que.front();
		day = temp.count;
		que.pop();

		for (int i = 0; i < 6; i++) {
			int nextH = temp.h + dh[i];
			int nextN = temp.n + dn[i];
			int nextM = temp.m + dm[i];

			if (nextH < 0 || nextH >= H || nextN < 0 || nextN >= N ||
				nextM < 0 || nextM >= M || storage[nextH][nextN][nextM] ||
				visited[nextH][nextN][nextM]) {
				continue;
			}

			t_point newPoint = {nextM, nextN, nextH, temp.count + 1};
			storage[nextH][nextN][nextM] = 1;
			visited[nextH][nextN][nextM] = true;
			que.push(newPoint);
		}
	}

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				if (!storage[i][j][k]) {
					std::cout << -1 << '\n';
					return (0);
				}
			}
		}
	}
	std::cout << day << '\n';
}
