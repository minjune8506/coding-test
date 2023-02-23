/**
 * @file 2178.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 미로 탐색
 * @date 2023-02-23
 *
 * N x M크기의 배열로 표현되는 미로.
 * 1은 이동할 수 있는 칸, 0은 이동할 수 없는 칸
 * (1,1)에서 (N,M)로 이동할 떄 최소 칸 수
 * 인접한 칸만 이동 가능하다.
 *
 * N, M (2 <= N, M <= 100)
 * 
 * BFS를 이용한 풀이
 */
#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

struct s_point {
	int x;
	int y;
	int count;
};

void solve(std::vector<int> &maze, int width, int height, int x, int y,
		   bool visited[]) {
	std::vector<int> answer;
	std::queue<struct s_point> que;

	s_point start = {x, y, 1};
	que.push(start);
	visited[y * width + x] = true;

	while (!que.empty()) {
		struct s_point point = que.front();
		que.pop();

		int px = point.x;
		int py = point.y;
		int count = point.count;

		if (px == width - 1 && py == height - 1) {
			answer.push_back(count);
		}

		if (px + 1 < width && !visited[py * width + (px + 1)] &&
			maze[py * width + (px + 1)]) {
			visited[py * width + (px + 1)] = true;
			struct s_point temp = {px + 1, py, count + 1};
			que.push(temp);
		}
		if (px - 1 >= 0 && !visited[py * width + (px - 1)] &&
			maze[py * width + (px - 1)]) {
			visited[py * width + (px - 1)] = true;
			struct s_point temp = {px - 1, py, count + 1};
			que.push(temp);
		}
		if (py + 1 < height && !visited[(py + 1) * width + px] &&
			maze[(py + 1) * width + px]) {
			visited[(py + 1) * width + px] = true;
			struct s_point temp = {px, py + 1, count + 1};
			que.push(temp);
		}
		if (py - 1 >= 0 && !visited[(py - 1) * width + px] &&
			maze[(py - 1) * width + px]) {
			visited[(py - 1) * width + px] = true;
			struct s_point temp = {px, py - 1, count + 1};
			que.push(temp);
		}
	}
	std::cout << *(std::min_element(answer.begin(), answer.end())) << std::endl;
}

int main(void) {
	int N, M;

	std::cin >> N >> M;
	std::vector<int> maze;
	for (int i = 0; i < N; i++) {
		std::string row;

		std::cin >> row;
		for (int j = 0; j < row.size(); j++) {
			maze.push_back(row.at(j) - '0');
		}
	}
	bool visitied[N * M];
	memset(visitied, false, sizeof(bool) * (N * M));
	solve(maze, M, N, 0, 0, visitied);
}
