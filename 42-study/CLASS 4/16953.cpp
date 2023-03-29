/**
 * @file 16953.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief A -> B
 * @date 2023-03-29
 *
 * 정수 A를 B로 바꾸려고 한다.
 * - 2를 곱한다.
 * - 1을 수의 가장 오른쪽에 추가한다.
 *
 * A -> B를 바꾸는데 필요한 연산의 최솟값
 *
 * 1 <= A <= B <= 10^9
 * 1,000,000,000
 */
#include <iostream>
#include <queue>

int A, B;

void bfs() {
	std::queue<std::pair<long long, int> > que;
	que.push(std::make_pair(A, 1));
	while (!que.empty()) {
		std::pair<long long, int> front = que.front();
		que.pop();
		if (front.first == B) {
			std::cout << front.second << '\n';
			return;
		}

		long long nx = front.first * 2;
		if (nx <= B) {
			que.push(std::make_pair(nx, front.second + 1));
		}

		nx = front.first * 10 + 1;
		if (nx <= B) {
			que.push(std::make_pair(nx, front.second + 1));
		}
	}
	std::cout << -1 << '\n';
}

int main(void) {
	std::cin >> A >> B;
	bfs();
}
