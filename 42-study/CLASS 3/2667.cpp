/**
 * @file 2667.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 단지번호붙이기
 * @date 2023-02-26
 *
 * 1 : 집이 있는 곳
 * 0 : 집이 없는 곳
 *
 * 연결된 집의 모임인 단지를 정의하고, 단지에 번호를 붙이려 한다.
 * 연결된 것 : 좌우, 위아래 다른 집이 있는 경우 (대각선 x)
 * 단지수를 출력 / 집의 수를 오름차순으로 정렬
 *
 * 지도의 크기 N (5 <= N <= 25)
 *
 * DFS 이용
 * - 입력을 받을때 숫자 -> 문자 변환에 신경써야함 ('0' -> 0)
 */
#include <algorithm>
#include <iostream>
#include <vector>

int N;
int map[25][25];
bool visited[25][25];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

std::vector<int> counts;
int count;

void dfs(int x, int y) {
	if (x >= N || y >= N || x < 0 || y < 0) {
		return;
	}
	visited[y][x] = true;
	count++;
	for (int i = 0; i < 4; i++) {
		int px = x + dx[i];
		int py = y + dy[i];
		if (!visited[py][px] && map[py][px]) {
			dfs(px, py);
		}
	}
}

int main(void) {
	// input
	std::cin >> N;
	for (int i = 0; i < N; i++) {
		std::string house;

		std::cin >> house;
		for (int j = 0; j < house.size(); j++) {
			map[i][j] = house[j] - '0';
		}
	}

	// search
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j] && map[i][j]) {
				dfs(j, i);
				counts.push_back(count);
				count = 0;
			}
		}
	}

	std::cout << counts.size() << '\n';
	std::sort(counts.begin(), counts.end());
	for (auto count : counts) {
		std::cout << count << '\n';
	}
}
