/**
 * @file 14500.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 테트로미노
 * @date 2023-03-22
 *
 * 5가지 테트리스 모양이 있다.
 * 크기가 N x M인 종이 위에 테트로미노 하나를 놓으려고 한다.
 * 테트로미노 하나를 적절히 놓아서 칸에 쓰여있는 수들의 합을 최대로
 * 하는 프로그램
 *
 * 4 <= N, M <= 500
 *
 * DFS Depth 4 -> ㅗ ㅜ ㅓ ㅏ 빼고 검사 가능
 * ㅗ ㅜ ㅓ ㅏ 는 따로 만들어서 검사
 */
#include <iostream>

int N, M;

int map[501][501];
bool visited[501][501];

int max = -1;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void shape1(int x, int y) {
	if (x + 2 < M && y - 1 >= 0) {
		int sum = map[y][x] + map[y][x + 1] + map[y][x + 2] + map[y - 1][x + 1];
		if (sum > max) {
			max = sum;
		}
	}
}

void shape2(int x, int y) {
	if (x + 2 < M && y + 1 < N) {
		int sum = map[y][x] + map[y][x + 1] + map[y][x + 2] + map[y + 1][x + 1];
		if (sum > max) {
			max = sum;
		}
	}
}

void shape3(int x, int y) {
	if (x + 1 < M && y + 1 < N && y - 1 >= 0) {
		int sum =
			map[y][x] + map[y][x + 1] + map[y - 1][x + 1] + map[y + 1][x + 1];
		if (sum > max) {
			max = sum;
		}
	}
}

void shape4(int x, int y) {
	if (x + 1 < M && y + 1 < N && y - 1 >= 0) {
		int sum = map[y][x] + map[y][x + 1] + map[y + 1][x] + map[y - 1][x];
		if (sum > max) {
			max = sum;
		}
	}
}

void dfs(int x, int y, int depth, int sum) {
	if (depth == 4) {
		if (sum > max) {
			max = sum;
		}
		return;
	}
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= M || nx < 0 || ny >= N || ny < 0 || visited[ny][nx]) {
			continue;
		}
		visited[ny][nx] = true;
		dfs(nx, ny, depth + 1, sum + map[ny][nx]);
		visited[ny][nx] = false;
	}
}

int main(void) {
	std::cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int score;
			std::cin >> score;
			map[i][j] = score;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			visited[i][j] = true;
			dfs(j, i, 1, map[i][j]);
			visited[i][j] = false;
			shape1(j, i);
			shape2(j, i);
			shape3(j, i);
			shape4(j, i);
		}
	}
	std::cout << max << '\n';
}
