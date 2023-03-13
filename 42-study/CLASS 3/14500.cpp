/**
 * @file 14500.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 테트로미노
 * @date 2023-03-11
 *
 * 폴리오미노랑 크기가 1x1인 정사각형을 여러개 붙인 도형이다.
 * - 정사각형은 서로 겹치면 안된다.
 * - 도형은 모두 연결되어 있어야 한다.
 * - 정사각형의 변끼리 연결되어 있어야 한다.
 *
 * 한 점에서 depth가 4인 것들을 dfs
 */
#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

int N, M;
int paper[501][501];
bool visited[501][501];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int answer = 0;

void dfs(int x, int y, int sum, int count) {
	if (count == 4) {
		answer = std::max(answer, sum);
		return;
	}

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= M || ny < 0 || ny >= N || visited[ny][nx]) {
			continue;
		}
		visited[ny][nx] = true;
		dfs(nx, ny, sum + paper[ny][nx], count + 1);
		visited[ny][nx] = false;
	}
}

void shape1(int x, int y) {
	if (x + 2 < M && y + 1 < N) {
		int sum = paper[y][x] + paper[y][x + 1] + paper[y][x + 2] +
				  paper[y + 1][x + 1];
		answer = std::max(sum, answer);
	}
}

void shape2(int x, int y) {
	if (x + 1 < M && y + 2 < N) {
		int sum = paper[y][x] + paper[y + 1][x] + paper[y + 2][x] +
				  paper[y + 1][x + 1];
		answer = std::max(sum, answer);
	}
}

void shape3(int x, int y) {
	if (x - 2 >= 0 && y - 1 >= 0) {
		int sum = paper[y][x] + paper[y][x - 1] + paper[y][x - 2] +
				  paper[y - 1][x - 1];
		answer = std::max(sum, answer);
	}
}

void shape4(int x, int y) {
	if (y + 2 < N && x - 1 >= 0) {
		int sum = paper[y][x] + paper[y + 1][x] + paper[y + 2][x] +
				  paper[y + 1][x - 1];
		answer = std::max(sum, answer);
	}
}

int main(void) {
	std::ios::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);

	std::cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			std::cin >> paper[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			visited[i][j] = true;
			dfs(j, i, 0, 0);
			visited[i][j] = false;

			shape1(j, i);
			shape2(j, i);
			shape3(j, i);
			shape4(j, i);
		}
	}
	std::cout << answer << '\n';
}
