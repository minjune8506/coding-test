/**
 * @file 1679.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 숨바꼭질
 * @date 2023-02-20
 *
 * 수빈이는 현재 점 N (0 <= N <= 100,000)에 있고,
 * 동생은 점 K (0 <= K <= 100,000)에 있다.
 *
 * 수빈이는 걸으면 X에서 X - 1 or X + 1로 이동한다.
 * 순간이동하면 2 * X의 위치로 이동한다.
 *
 * 수빈이가 동생을 찾을 수 있는 가장 빠른 시간이 몇 초 후인지 구해라
 *
 * - 완전탐색 문제? (시간 제한 2초)
 * 5 17
 * 5 -> 10 -> 9 -> 18 -> 17 (5)
 *
 * 모르겠음 -> 힌트 (BFS)
 * BFS 시간 복잡도 -> 3^n승.. 메모리 초과 -> visited 사용
 */
#include <cstring>
#include <iostream>
#include <queue>

int bfs(int start, int end, bool visited[]) {
	std::queue<std::pair<int, int> > que;
	que.push(std::make_pair(start, 0));
	while (!que.empty()) {
		int key = que.front().first;
		int time = que.front().second;
		visited[key] = true;
		if (key == end) {
			return que.front().second;
		}
		que.pop();
		if (key > 0 && key <= 100001 && !visited[key - 1]) {
			que.push(std::make_pair(key - 1, time + 1));
		}
		if (key < 100000 && !visited[key + 1]) {
			que.push(std::make_pair(key + 1, time + 1));
		}
		if (key <= 50000 && !visited[key * 2]) {
			que.push(std::make_pair(key * 2, time + 1));
		}
	}
}

int main(void) {
	int N, K;

	std::cin >> N >> K;
	bool visited[100001] = {
		0,
	};
	std::cout << bfs(N, K, visited) << std::endl;
}
