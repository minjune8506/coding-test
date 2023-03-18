/**
 * @file 1697.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 숨바꼭질
 * @date 2023-03-18
 *
 * 수빈이는 점 N (0 <= N <= 100,000)에 있고
 * 동생은 점 K (0 <= K <= 100,000)에 있다.
 * 수빈이의 위치가 X면 1초후 X - 1 / X + 1로 이동한다.
 * 순간이동을 하는 경우 1초 후 2 * X로 이동한다.
 *
 * 동생을 찾을 수 있는 가장 빠른 시간은 몇초후인가?
 *
 * - BFS
 */
#include <iostream>
#include <queue>

int N, K;
bool visited[100001];

void bfs() {
	std::queue<std::pair<int, int> > que;

	visited[N] = true;
	que.push(std::make_pair(N, 0));
	while (!que.empty()) {
		std::pair<int, int> front = que.front();
		que.pop();

		if (front.first == K) {
			std::cout << front.second << '\n';
			break;
		}
		int pos = front.first;
		int time = front.second;

		if (pos + 1 <= 100000 && !visited[pos + 1]) {
			visited[pos + 1] = true;
			que.push(std::make_pair(pos + 1, time + 1));
		}
		if (pos - 1 >= 0 && !visited[pos - 1]) {
			visited[pos - 1] = true;
			que.push(std::make_pair(pos - 1, time + 1));
		}
		if (pos * 2 <= 100000 && !visited[pos * 2]) {
			visited[pos * 2] = true;
			que.push(std::make_pair(pos * 2, time + 1));
		}
	}
}

int main(void) {
	std::cin >> N >> K;
	bfs();
}
