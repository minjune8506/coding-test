/**
 * @file 16928.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 뱀과 사다리 게임
 * @date 2023-03-13
 *
 * 주사위를 이용한다.
 * 게임의 크기는 10x10이다. (1 ~ 100)
 * 주사위를 굴려 나온 수만큼 이동한다.
 * 100번칸을 넘어가면 이동할 수 없다.
 * 도착한 칸이 사다리면 사다리를 타고 위로 올라간다.
 * 뱀이 있으면 뱀을 따라 내려간다.
 * 1번에서 100번으로 도착하는 것이 목표
 * 주사위를 굴려야 하는 횟수의 최솟값
 *
 * 사다리 수 (1 <= N <= 15)
 * 뱀의 수 M (1 <= M <= 15)
 * 사다리 정보 x, y (x < y)
 * 뱀의 정보 u, v (u > v)
 *
 * 최솟값을 구하는 문제 -> BFS로 해결
 */
#include <iostream>
#include <map>
#include <queue>

int N, M;

std::map<int, int> ladders;
std::map<int, int> snakes;
bool visited[101];

void bfs() {
	std::queue<std::pair<int, int> > que;

	que.push(std::make_pair(1, 0));
	visited[1] = true;

	while (!que.empty()) {
		std::pair<int, int> front = que.front();
		que.pop();

		if (front.first == 100) {
			std::cout << front.second << '\n';
			break;
		}

		for (int i = 1; i <= 6; i++) {
			int pos = front.first + i;
			if (visited[pos]) {
				continue;
			}

			std::pair<int, int> dest;

			dest.first = pos;
			auto found = ladders.find(pos);
			if (found != ladders.end()) {
				dest.first = found->second;
			} else if ((found = snakes.find(pos)) != snakes.end()) {
				dest.first = found->second;
			}

			if (dest.first > 100) {
				continue;
			}
			dest.second = front.second + 1;
			que.push(dest);
			visited[dest.first] = true;
		}
	}
}

int main(void) {
	std::cin >> N >> M;

	for (int i = 0; i < N; i++) {
		int x, y;
		std::cin >> x >> y;
		ladders.insert(std::make_pair(x, y));
	}
	for (int i = 0; i < M; i++) {
		int u, v;
		std::cin >> u >> v;
		snakes.insert(std::make_pair(u, v));
	}
	bfs();
}
