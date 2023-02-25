/**
 * @file 2667.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 단지번호붙이기
 * @date 2023-02-24
 *
 * 정사각형 모양의 지도가 있다.
 * 1은 집이 있는 곳, 0은 집이 없는 곳을 나타낸다.
 * 연결된 집의 모임인 단지를 정의하고, 단지에 번호를 붙이려 한다.
 * 상하좌우에 다른 집이 있으면 연결된 것이다. (대각 x)
 *
 * 단지수를 출력하고, 각 단지에 속하는 집의 수를 오름차순으로 정렬하여 출려
 */
#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

int houses = 0;

void dfs(std::vector<int> houseMap[], int N, bool visited[], int x, int y) {
	houses++;
	visited[y * N + x] = true;
	if (x + 1 < N && !visited[y * N + (x + 1)] && houseMap[y][x + 1]) {
		dfs(houseMap, N, visited, x + 1, y);
	}
	if (x - 1 >= 0 && !visited[y * N + (x - 1)] && houseMap[y][x - 1]) {
		dfs(houseMap, N, visited, x - 1, y);
	}
	if (y + 1 < N && !visited[(y + 1) * N + x] && houseMap[y + 1][x]) {
		dfs(houseMap, N, visited, x, y + 1);
	}
	if (y - 1 >= 0 && !visited[(y - 1) * N + x] && houseMap[y - 1][x]) {
		dfs(houseMap, N, visited, x, y - 1);
	}
}

int main(void) {
	int N;

	std::cin >> N;
	std::vector<int> houseMap[N];

	for (int i = 0; i < N; i++) {
		std::string row;

		std::cin >> row;
		for (int j = 0; j < row.size(); j++) {
			houseMap[i].push_back(row.at(j) - '0');
		}
	}

	bool visited[N * N];
	int count = 0;
	memset(visited, false, N * N);

	std::vector<int> counts;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i * N + j] && houseMap[i][j]) {
				dfs(houseMap, N, visited, j, i);
				count++;
				counts.push_back(houses);
				houses = 0;
			}
		}
	}

	std::cout << count << '\n';
	std::sort(counts.begin(), counts.end());
	for (auto it : counts) {
		std::cout << it << '\n';
	}
}
