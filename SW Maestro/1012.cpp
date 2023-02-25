/**
 * @file 1012.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 유기농 배추
 * @date 2023-02-24
 *
 * 어떤 배추에 지렁이가 한마리라도 살고 있으면 인접한 배추는 해충으로부터
 * 보호받을 수 있다.
 * 인접한 배추는 상하좌우 네 방향에 다른 배추가 위치한 경우
 *
 * 몇마리의 지렁이가 필요한가?
 * 0 : 배추가 심어져 있지 않은 땅
 * 1 : 배추가 심어져 있는 땅
 *
 * 테스트 케이스 개수 T
 * 가로 길이 M (1 <= M <= 50)
 * 세로 길이 N (1 <= N <= 50)
 * 배추가 있는 위치의 개수 (1 <= K <= 2500)
 */
#include <cstring>
#include <iostream>

int land[50][50];
bool visited[50][50];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void dfs(int x, int y, int width, int height) {
	visited[y][x] = true;
	for (int i = 0; i < 4; i++) {
		int px = x + dx[i];
		int py = y + dy[i];

		if (px >= width || py >= height || px < 0 || py < 0) {
			continue;
		}

		if (!visited[py][px] && land[py][px]) {
			dfs(px, py, width, height);
		}
	}
}

int main(void) {
	int testCase;

	std::cin >> testCase;
	for (int i = 0; i < testCase; i++) {
		int count = 0;
		memset(visited, false, 50 * 50);
		memset(land, 0, sizeof(int) * (50 * 50));

		int width, height, cabbage;
		std::cin >> width >> height >> cabbage;

		for (int j = 0; j < cabbage; j++) {
			int x, y;
			std::cin >> x >> y;
			land[y][x] = 1;
		}

		for (int j = 0; j < height; j++) {
			for (int k = 0; k < width; k++) {
				if (!visited[j][k] && land[j][k]) {
					dfs(k, j, width, height);
					count++;
				}
			}
		}
		std::cout << count << '\n';
	}
}
