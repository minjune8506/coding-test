/**
 * @file 12851.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 숨바꼭질 2
 * @date 2023-04-28
 *
 * N에서 K로 이동
 * 1초 : X - 1 or X + 1
 * 순간이동 1초 : 2X
 *
 * 가장 빠른 시간은 몇 초 후인지
 * 가장 빠른 시간으로 찾는 방법이 몇 가지인지 구해라
 */
#include <climits>
#include <iostream>
#include <map>
#include <queue>
#include <vector>

int N, K;
bool visited[200001];
int count;
int answer;

void bfs() {
	std::queue<std::pair<int, int> > que;

	que.push(std::make_pair(N, 0));
	visited[N] = true;

	while (!que.empty()) {
		std::pair<int, int> front = que.front();
		que.pop();
		visited[front.first] = true;

		if (count && front.first == K && front.second == answer) {
			answer = front.second;
			count++;
			continue;
		}

		if (!count && front.first == K) {
			answer = front.second;
			count++;
			continue;
		}

		int nx = front.first + 1;
		if (nx <= 100000 && !visited[nx]) {
			que.push({nx, front.second + 1});
		}

		nx = front.first - 1;
		if (nx >= 0 && !visited[nx]) {
			que.push({nx, front.second + 1});
		}

		nx = front.first * 2;
		if (nx <= 100000 && !visited[nx]) {
			que.push({nx, front.second + 1});
		}
	}
}

int main(void) {
	std::cin >> N >> K;
	bfs();
	std::cout << answer << '\n' << count << '\n';
}

// 1 3
// 2
// 3

// 1 3
// 2
// 3
