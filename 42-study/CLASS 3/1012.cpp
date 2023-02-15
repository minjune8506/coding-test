/**
 * @file 1012.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 유기농 배추
 * @date 2023-02-14
 *
 * 어떤 배추에 배추 흰지렁이가 한 마리라도 살고 있으면 이 지렁이는
 * 인접한 다른 배추로 이동할 수 있어, 해충으로부터 보호받을 수 있다.
 *
 * 인접하다는 것은 배추의 상하좌우 네 방향에 다른 배추가 위치한 경우
 * 인접하다는 것이다.
 *
 * 배추를 군데군데 심어놓았고, 배추가 모여있는 곳에는 지렁이 한마리만 있으면
 * 된다. 서로 인접해있는 배추들이 몇 군데에 퍼져있는지 조사하면 지렁이가 얼만큼
 * 필요한지 알아낼 수 있다.
 *
 * 배추밭의 가로길이 M (1 <= M <= 50)
 * 세로 길이 N (1 <= N <= 50)
 * 배추가 심어져 있는 위치의 개수 (1 <= K <= 2500)
 * 배추의 위치 X (0 <= X <= M - 1), Y (0 <= Y <= N - 1)
 */
#include <cstring>
#include <iostream>

int cabbagePath[51][51];
bool visited[51][51];

void dfs(int y, int x, int w, int h) {
	if (x > w || x < 0 || y > h || y < 0) {
		return;
	}
	visited[y][x] = true;

	if (!visited[y][x + 1] && cabbagePath[y][x + 1]) {
		dfs(y, x + 1, w, h);
	}
	if (!visited[y + 1][x] && cabbagePath[y + 1][x]) {
		dfs(y + 1, x, w, h);
	}
	if (!visited[y - 1][x] && cabbagePath[y - 1][x]) {
		dfs(y - 1, x, w, h);
	}
	if (!visited[y][x - 1] && cabbagePath[y][x - 1]) {
		dfs(y, x - 1, w, h);
	}
}

int solve() {
	int width, height, cabbageCount;  // width : 가로, height : 세로

	std::cin >> width >> height >> cabbageCount;
	for (int i = 0; i < cabbageCount; i++) {
		int x, y;

		std::cin >> x >> y;
		cabbagePath[y][x] = 1;
	}

	int count = 0;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (!visited[i][j] && cabbagePath[i][j]) {
				dfs(i, j, width, height);
				count++;
			}
		}
	}
	return count;
}

int main(void) {
	int tc;

	std::cin >> tc;
	for (int i = 0; i < tc; i++) {
		std::cout << solve() << '\n';
		memset(cabbagePath, 0, sizeof(cabbagePath));
		memset(visited, false, sizeof(visited));
	}
}
