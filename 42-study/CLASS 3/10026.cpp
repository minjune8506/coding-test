/**
 * @file 10026.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 적록색약
 * @date 2023-03-06
 *
 * NxN인 칸 안에 R, G, B중 하나를 색칠한 그림이 있다.
 * 구역은 같은 색으로 이루어져 있다.
 * 상하좌우로 같은 색이 인접해 있는 경우 같은 구역에 속한다.
 * 적록색약은 R과 G를 구분못한다.
 *
 * 적록색약이 봤을때랑 아닌 사람이 봤을때 구역의 수를 구하는 프로그램
 *
 * 1 <= N <= 100
 */
#include <iostream>
#include <cstring>

char sector[101][101];
bool visited[101][101];

void dfs(int x, int y) {
	visited[y][x] = true;

	char color = sector[y][x];

	if (x + 1 <= 100 && !visited[y][x + 1] && color == sector[y][x + 1]) {
		dfs(x + 1, y);
	}
	if (x - 1 >= 0 && !visited[y][x - 1] && color == sector[y][x - 1]) {
		dfs(x - 1, y);
	}
	if (y + 1 <= 100 && !visited[y + 1][x] && color == sector[y + 1][x]) {
		dfs(x, y + 1);
	}
	if (y - 1 >= 0 && !visited[y - 1][x] && color == sector[y - 1][x]) {
		dfs(x, y - 1);
	}
}

int main(void) {
	int N;
	std::cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			char color;

			std::cin >> color;
			sector[i][j] = color;
		}
	}

	int count = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j]) {
				dfs(j, i);
				count++;
			}
		}
	}
	std::cout << count << ' ';

	memset(visited, false, 101 * 101);
	count = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (sector[i][j] == 'G') {
				sector[i][j] = 'R';
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j]) {
				dfs(j, i);
				count++;
			}
		}
	}

	std::cout << count << '\n';
}
