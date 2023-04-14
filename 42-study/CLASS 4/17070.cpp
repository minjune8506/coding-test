/**
 * @file 17070.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 파이프 옮기기 1
 * @date 2023-04-14
 *
 * NxN 격자판 집
 * 각 칸은 (r, c)로 나타낸다. 둘다 1이상
 *
 * 파이프를 밀 수 있는 방향은 →, ↘, ↓ 방향
 * 밀면서 회전 가능
 *
 * 가장 처음의 파이프는 (1, 1)와 (1, 2)를 차지하고 있고
 * 방향은 가로이다.
 *
 * 파이프의 한쪽 끝을 (N, N)로 이동시키는 방법의 개수?
 *
 * N (3 <= N <= 16)
 * 0 : 빈칸 1 : 벽
 *
 * 완전탐색으로 끝에 도달하는 경우의 수를 센다.
 * 어떤 모양을 하고 있는지 기억해아함..
 */

#include <iostream>
#define WIDTH 0
#define HEIGHT 1
#define DIAGONAL 2

int house[16][16];
int N;
bool visited[16][16];
int count = 0;

void dfs(int i, int j, int shape) {
	visited[i][j] = true;
	if (i == N - 1 && j == N - 1) {
		count++;
		return;
	}

	int nx = j + 1;
	int ny = i;

	if (nx < N && !house[ny][nx] && !visited[ny][nx] && shape != HEIGHT) {
		visited[ny][nx] = true;
		dfs(ny, nx, WIDTH);
		visited[ny][nx] = false;
	}
	ny = i + 1;
	if (nx < N && ny < N && !house[ny][nx] && !house[i + 1][j] &&
		!house[i][j + 1] && !visited[ny][nx]) {
		visited[ny][nx] = true;
		dfs(ny, nx, DIAGONAL);
		visited[ny][nx] = false;
	}
	nx = j;
	if (ny < N && !house[ny][nx] && !visited[ny][nx] && shape != WIDTH) {
		visited[ny][nx] = true;
		dfs(ny, nx, HEIGHT);
		visited[ny][nx] = false;
	}
}

int main(void) {
	std::cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			std::cin >> house[i][j];
		}
	}

	dfs(0, 1, WIDTH);

	std::cout << count << '\n';
}
