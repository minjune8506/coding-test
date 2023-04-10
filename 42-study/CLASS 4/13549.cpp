/**
 * @file 13549.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 숨바꼭질 3
 * @date 2023-04-10
 *
 * 수빈은 점 N (0 <= N <= 100,000)에 있고
 * 동생은 점 K (0 <= K <= 100,000)에 있다.
 *
 * X -> X - 1 / X + 1 (1초후)
 * 	 -> 2X (0초후)
 *
 * 동생을 찾을 수 있는 가장 빠른 시간은 몇초후인가?
 *
 * - K보다 큰 위치들을 제외했었음
 * 	- x * 2 - 1이 최소거리일수도 있음 -> MAX_SIZE로 변경
 * - 순간이동하는것과 + 1 - 1 하는것은 가중치가 다름
 *   - 순간이동하는 것들은 앞에,  + 1, - 1은 뒤에 추가
 * - 우선순위큐 / 다익스트라 알고리즘으로도 풀이 가능
 */
#include <deque>
#include <iostream>

#define MAX_SIZE 100001

int N, K;
bool visited[MAX_SIZE];

void bfs() {
	std::deque<std::pair<int, int> > que;
	que.push_back(std::make_pair(N, 0));
	visited[N] = true;

	while (!que.empty()) {
		std::pair<int, int> pos = que.front();
		que.pop_front();

		if (pos.first == K) {
			std::cout << pos.second << '\n';
			break;
		}

		int npos = pos.first * 2;
		if (npos <= MAX_SIZE && !visited[npos]) {
			visited[npos] = true;
			que.push_front(std::make_pair(npos, pos.second));
		}

		npos = pos.first + 1;
		if (npos <= MAX_SIZE && !visited[npos]) {
			visited[npos] = true;
			que.push_back(std::make_pair(npos, pos.second + 1));
		}

		npos = pos.first - 1;
		if (npos >= 0 && !visited[npos]) {
			visited[npos] = true;
			que.push_back(std::make_pair(npos, pos.second + 1));
		}
	}
}

int main(void) {
	std::cin >> N >> K;
	bfs();
}
